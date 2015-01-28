$NetBSD: patch-jpeglib.h,v 1.2 2015/01/28 21:51:02 rjs Exp $

--- jpeglib.h.orig	2014-11-25 10:07:43.000000000 +0000
+++ jpeglib.h
@@ -28,6 +28,7 @@
 #endif
 #include "jmorecfg.h"           /* seldom changed options */
 
+#include <stdio.h>
 
 #ifdef __cplusplus
 #ifndef DONT_USE_EXTERN_C
