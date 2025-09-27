Transign Texta code

#include "SoftwareSerial.h"
#include <LiquidCrystal_I2C.h>

SoftwareSerial mySerial(3, 2);  // HC-05 Bluetooth module connected to pins 3 (TX) and 2 (RX)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C LCD address 0x27, 16 columns, 2 rows

#define blue 4   // Define correct LED pin
#define green 5  // Define correct LED pin
#define red 6    // Define correct LED pin

unsigned int f, g, h;  // Variables to store flex sensor readings

void setup() {
    pinMode(blue, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(red, OUTPUT);

    Serial.begin(9600);
    mySerial.begin(9600);

    lcd.init();  // Initialize the LCD
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("  Welcome To");
    lcd.setCursor(0, 1);
    lcd.print("JustDoElectronic");
    delay(3000);
    lcd.clear();
}

void loop() {
    f = analogRead(A1);  // Read from flex sensor 1
    g = analogRead(A2);  // Read from flex sensor 2
    h = analogRead(A3);  // Read from flex sensor 3

    if (f <= 722) {
        digitalWrite(blue, HIGH);
        digitalWrite(green, LOW);
        digitalWrite(red, LOW);
        mySerial.println("Plz Give Me Water");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  Plz Give Me");
        lcd.setCursor(0, 1);
        lcd.print("     Water   ");
        delay(3000);
    } 
    else if (g <= 670) {
        digitalWrite(green, HIGH);
        digitalWrite(blue, LOW);
        digitalWrite(red, LOW);
        mySerial.println("Plz Give Me Food");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  Plz Give Me ");
        lcd.setCursor(0, 1);
        lcd.print("     Food   ");
        delay(3000);
    } 
    else if (h <= 675) {
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        digitalWrite(blue, LOW);
        mySerial.println("Plz Give Me Tea");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  Plz Give Me");
        lcd.setCursor(0, 1);
        lcd.print("     Tea   ");
        delay(3000);
    } else {
        digitalWrite(blue, LOW);
        digitalWrite(green, LOW);
        digitalWrite(red, LOW);
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" If Anything");
    lcd.setCursor(0, 1);
    lcd.print("  You Want ");
    delay(200);
}
