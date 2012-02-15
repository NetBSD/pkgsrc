$NetBSD: patch-playay_ayplay.c,v 1.1 2012/02/15 22:23:16 hans Exp $

--- playay/ayplay.c.orig	2011-11-17 22:46:08.000000000 +0100
+++ playay/ayplay.c	2012-01-18 12:00:17.650251502 +0100
@@ -1129,7 +1129,7 @@ void __attribute__ ((visibility ("intern
 	aybufrate=256*sp;
 }
 
-void __attribute__ ((visibility ("internal"))) aySetVolume(unsigned char vol_, signed char bal_, signed char pan_, unsigned char opt)
+void __attribute__ ((visibility ("internal"))) aySetVolume(uint8_t vol_, int8_t bal_, int8_t pan_, uint8_t opt)
 {
 	pan=pan_;
 	volr=voll=vol_*4;
