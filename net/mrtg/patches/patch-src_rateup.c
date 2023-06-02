$NetBSD: patch-src_rateup.c,v 1.2 2023/06/02 14:23:40 wiz Exp $

--- src/rateup.c.orig	2007-08-08 20:01:48.000000000 +0000
+++ src/rateup.c
@@ -48,11 +48,6 @@
 #define GFORM_GD gdImagePng
 #endif
 
-/* BSD* does not have/need malloc.h */
-#if !defined(bsdi) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__APPLE__)
-#include <malloc.h>
-#endif
-
 /* MSVCRT.DLL does not know %ll in printf */
 #ifdef __MINGW32_VERSION
 #define LLD "%I64d"
