$NetBSD: patch-include_AL_al.h,v 1.1 2025/03/30 09:32:08 nia Exp $

Fix SunOS build, int8_t is not always the same as signed char.

--- include/AL/al.h.orig	2025-03-24 15:39:07.740729073 +0000
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
