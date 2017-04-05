$NetBSD: patch-lrzip.h,v 1.2 2017/04/05 17:34:39 adam Exp $

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
