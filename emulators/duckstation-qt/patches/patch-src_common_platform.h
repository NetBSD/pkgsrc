$NetBSD: patch-src_common_platform.h,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/common/platform.h.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/common/platform.h
@@ -57,6 +57,8 @@
 #define SYSTEM_STR "Linux"
 #elif defined(__FreeBSD__)
 #define SYSTEM_STR "FreeBSD"
+#elif defined(__NetBSD__)
+#define SYSTEM_STR "NetBSD"
 #elif defined(__APPLE__)
 #define SYSTEM_STR "macOS"
 #else
