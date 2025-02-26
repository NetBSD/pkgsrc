$NetBSD: patch-src_utils.h,v 1.1 2025/02/26 14:03:06 hauke Exp $

Add NetBSD stat/lstat

--- src/utils.h.orig	2025-02-26 12:51:48.963122972 +0000
+++ src/utils.h
@@ -54,6 +54,11 @@
 #define LSTAT lstat
 #endif
 
+#ifdef __NetBSD__
+#define STRUCT_STAT struct stat
+#define LSTAT lstat
+#endif
+
 #ifdef sun
 #define STRUCT_STAT struct stat64
 #define LSTAT lstat64
