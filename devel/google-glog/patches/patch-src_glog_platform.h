$NetBSD: patch-src_glog_platform.h,v 1.2 2025/02/18 09:03:18 adam Exp $

Support illumos.

--- src/glog/platform.h.orig	2024-06-08 15:07:34.000000000 +0000
+++ src/glog/platform.h
@@ -53,6 +53,8 @@
 #  define GLOG_OS_OPENBSD
 #elif defined(__EMSCRIPTEN__)
 #  define GLOG_OS_EMSCRIPTEN
+#elif defined(__illumos__)
+#  define GLOG_OS_ILLUMOS
 #else
 // TODO(hamaji): Add other platforms.
 #error Platform not supported by glog. Please consider to contribute platform information by submitting a pull request on Github.
