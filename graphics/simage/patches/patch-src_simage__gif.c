$NetBSD: patch-src_simage__gif.c,v 1.1 2024/10/08 20:43:17 rjs Exp $

--- src/simage_gif.c.orig	2024-09-17 15:41:13.777192650 +0000
+++ src/simage_gif.c
@@ -34,7 +34,7 @@
 #if GIFLIB_MAJOR > 5 || GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 2 || GIFLIB_MAJOR == 5 && GIFLIB_MINOR == 1 && GIFLIB_RELEASE >= 9
 //see https://sourceforge.net/p/giflib/bugs/132/
 //and https://sourceforge.net/p/giflib/bugs/142/
-#include <quantize.h>
+//#include <quantize.h>
 #endif
 
 #if GIFLIB_MAJOR > 5 || GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1
