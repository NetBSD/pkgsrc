$NetBSD: patch-src_util_strndup.h,v 1.1 2018/10/07 23:49:31 ryoon Exp $

Provide compat strndup for older Darwin.

--- src/util/strndup.h.orig	2017-05-10 14:13:58.000000000 +0000
+++ src/util/strndup.h
@@ -24,7 +24,7 @@
 #ifndef STRNDUP_H
 #define STRNDUP_H
 
-#if defined(_WIN32)
+#if defined(_WIN32) || (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070)
 
 #include <stdlib.h> // size_t
 #include <string.h>
