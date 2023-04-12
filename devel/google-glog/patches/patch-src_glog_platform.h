$NetBSD: patch-src_glog_platform.h,v 1.1 2023/04/12 10:39:21 jperkin Exp $

Support illumos.

--- src/glog/platform.h.orig	2022-04-04 22:03:27.000000000 +0000
+++ src/glog/platform.h
@@ -50,6 +50,8 @@
 #define GLOG_OS_NETBSD
 #elif defined(__OpenBSD__)
 #define GLOG_OS_OPENBSD
+#elif defined(__illumos__)
+#define GLOG_OS_ILLUMOS
 #else
 // TODO(hamaji): Add other platforms.
 #error Platform not supported by glog. Please consider to contribute platform information by submitting a pull request on Github.
