$NetBSD: patch-jpeglib.h,v 1.1 2013/10/11 14:54:06 joerg Exp $

--- jpeglib.h.orig	2013-10-11 13:07:30.000000000 +0000
+++ jpeglib.h
@@ -28,6 +28,7 @@
 #endif
 #include "jmorecfg.h"		/* seldom changed options */
 
+#include <stdio.h>
 
 #ifdef __cplusplus
 #ifndef DONT_USE_EXTERN_C
