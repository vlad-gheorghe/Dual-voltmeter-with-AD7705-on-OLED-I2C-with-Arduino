/*
 * AD770X Library
 * sample code (AD7706)
 * Kerry D. Wong
 * http://www.kerrywong.com
 * 3/2011
 */

#include <AD770X.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

AD770X ad7706(2.5);
float v1;
double v2;

void setup()
{
  Serial.begin(9600);

display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  display.display();

  ad7706.reset();
  ad7706.init(AD770X::CHN_AIN1);  
  ad7706.init(AD770X::CHN_AIN2);
  
  
}

void loop()
{
   v1 = ad7706.readADResult(AD770X::CHN_AIN1);
  Serial.print(v1*2)*10;
display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("R =");
 //  display.setCursor(100,0);
//  display.println("MO");
  display.setCursor(40,0);
   display.setTextColor(WHITE,BLACK);
  // if((v1*20)<10){
  display.fillRect(39,0,90,17,BLACK);  
  //  display.println(0+v1*20);}
  display.println(v1*2000);
 display.display();
 delay(50);
 
  v2 = ad7706.readADResult(AD770X::CHN_AIN2);
   display.setCursor(0,18);
  display.println("U2=");
  display.setCursor(100,18);
  display.println(" V");
  display.setCursor(40,18);
 
   display.setTextColor(WHITE,BLACK);
  display.println(v2*2);
   display.display();
 delay(50);
  Serial.print(" : ");
  Serial.println(v2*2);
 

  
  
  
}
