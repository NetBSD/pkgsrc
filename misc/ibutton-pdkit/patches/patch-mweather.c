$NetBSD: patch-mweather.c,v 1.1 2013/01/11 13:30:32 joerg Exp $

--- mweather.c.orig	2013-01-11 01:31:18.000000000 +0000
+++ mweather.c
@@ -72,7 +72,7 @@ uchar TempSN[8],CountSN[8],SwitchSN[8], 
 //----------------------------------------------------------------------
 //  Main Test for Weather Station
 //
-int main(short argc, char **argv)
+int main(int argc, char **argv)
 {
    WeatherStruct weather1;
 //   WeatherStruct weather1 = { {0x20, 0x7A, 0x01, 0x01, 0x00, 0x00, 0x00, 0xFA},
