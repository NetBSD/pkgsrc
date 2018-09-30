$NetBSD: patch-src_common_config.h,v 1.1 2018/09/30 19:17:24 maya Exp $

https://bitbucket.org/rude/love/issue/867/netbsd-support

--- src/common/config.h.orig	2013-12-13 22:08:44.000000000 +0000
+++ src/common/config.h
@@ -25,7 +25,7 @@
 #if defined(WIN32) || defined(_WIN32)
 #	define LOVE_WINDOWS 1
 #endif
-#if defined(linux) || defined(__linux) || defined(__linux__)
+#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__NetBSD__)
 #	define LOVE_LINUX 1
 #endif
 #if defined(__APPLE__)
