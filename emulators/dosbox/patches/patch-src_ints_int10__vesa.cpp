$NetBSD: patch-src_ints_int10__vesa.cpp,v 1.1 2018/03/21 13:48:48 kamil Exp $

Fix C++11 syntax of a literal.

--- src/ints/int10_vesa.cpp.orig	2010-05-10 17:43:54.000000000 +0000
+++ src/ints/int10_vesa.cpp
@@ -39,7 +39,7 @@ static struct {
 static char string_oem[]="S3 Incorporated. Trio64";
 static char string_vendorname[]="DOSBox Development Team";
 static char string_productname[]="DOSBox - The DOS Emulator";
-static char string_productrev[]="DOSBox "VERSION;
+static char string_productrev[]="DOSBox " VERSION;
 
 #ifdef _MSC_VER
 #pragma pack (1)
@@ -518,4 +518,3 @@ void INT10_SetupVESA(void) {
 	phys_writew( Real2Phys(int10.rom.pmode_interface) + 6, 0);
 	int10.rom.pmode_interface_size=int10.rom.used - RealOff( int10.rom.pmode_interface );
 }
-
