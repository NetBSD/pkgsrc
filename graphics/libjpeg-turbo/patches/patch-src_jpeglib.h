$NetBSD: patch-src_jpeglib.h,v 1.1 2024/12/24 15:39:44 adam Exp $

--- src/jpeglib.h.orig	2024-12-12 20:46:51.000000000 +0000
+++ src/jpeglib.h
@@ -43,6 +43,7 @@
 #endif
 #include "jmorecfg.h"           /* seldom changed options */
 
+#include <stdio.h>
 
 #ifdef __cplusplus
 #ifndef DONT_USE_EXTERN_C
