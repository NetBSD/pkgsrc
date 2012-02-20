$NetBSD: patch-src-cmos.c,v 1.1 2012/02/20 15:45:19 reinoud Exp $

--- src/cmos.c.orig	2010-10-25 13:51:42.000000000 +0000
+++ src/cmos.c
@@ -5,7 +5,7 @@
 
 uint8_t cmos[64];
 
-int cmosrw,cmosstrobe,cmosold,cmosaddr,cmosena;
+uint8_t cmosrw,cmosstrobe,cmosold,cmosaddr,cmosena;
 
 void cmosupdate(uint8_t IC32, uint8_t sdbval)
 {
