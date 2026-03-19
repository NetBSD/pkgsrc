$NetBSD: patch-preset.c,v 1.1 2026/03/19 14:55:21 nia Exp $

Modern GCC no longer likes implicit int. ANSIfy.

--- preset.c.orig	2026-03-19 14:44:51.705585693 +0000
+++ preset.c
@@ -46,8 +46,7 @@ unsigned char presetmap[]=
 
 
 
-int c_preset(argc, argv)
-char *argv[];
+int c_preset(int argc, char *argv[])
 {
     register int n;
     unsigned int hcode, unit, unitx10, bits;
