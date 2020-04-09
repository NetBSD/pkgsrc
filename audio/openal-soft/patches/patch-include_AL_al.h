$NetBSD: patch-include_AL_al.h,v 1.1 2020/04/09 13:35:21 jperkin Exp $

Fix SunOS build, int8_t is not always the same as signed char.

--- include/AL/al.h.orig	2020-01-24 07:28:45.000000000 +0000
+++ include/AL/al.h
@@ -41,7 +41,12 @@ typedef char ALboolean;
 typedef char ALchar;
 
 /** signed 8-bit 2's complement integer */
+#ifdef __sun
+#include <inttypes.h>
+typedef int8_t ALbyte;
+#else
 typedef signed char ALbyte;
+#endif
 
 /** unsigned 8-bit integer */
 typedef unsigned char ALubyte;
