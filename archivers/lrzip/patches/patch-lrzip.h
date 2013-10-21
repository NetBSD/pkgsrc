$NetBSD: patch-lrzip.h,v 1.1 2013/10/21 11:29:05 fhajny Exp $

stdarg needed with modern GCC for va_list.
--- Lrzip.h.orig	2012-05-10 12:45:41.000000000 +0000
+++ Lrzip.h
@@ -28,6 +28,8 @@
 # include <inttypes.h>
 #endif
 
+#include <stdarg.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif
