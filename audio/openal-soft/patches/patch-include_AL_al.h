$NetBSD: patch-include_AL_al.h,v 1.2 2023/02/16 15:15:55 wiz Exp $

Fix SunOS build, int8_t is not always the same as signed char.

--- include/AL/al.h.orig	2023-02-03 14:48:18.000000000 +0000
+++ include/AL/al.h
@@ -41,7 +41,12 @@ typedef char ALboolean;
 typedef char ALchar;
 
 /** signed 8-bit integer */
+#ifdef __sun
+#include <inttypes.h>
+typedef int8_t ALbyte;
+#else
 typedef signed char ALbyte;
+#endif
 
 /** unsigned 8-bit integer */
 typedef unsigned char ALubyte;
