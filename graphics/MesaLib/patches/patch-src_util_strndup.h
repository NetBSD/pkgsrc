$NetBSD: patch-src_util_strndup.h,v 1.1 2016/02/23 11:16:55 jperkin Exp $

Provide compat strndup for older Darwin.

--- src/util/strndup.h.orig	2016-01-22 15:44:31.000000000 +0000
+++ src/util/strndup.h
@@ -25,7 +25,7 @@
 
 #include <stdlib.h> // size_t
 
-#if defined(_WIN32)
+#if defined(_WIN32) || (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070)
 
 #ifdef __cplusplus
 extern "C" {
