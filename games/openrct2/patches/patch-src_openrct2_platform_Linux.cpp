$NetBSD: patch-src_openrct2_platform_Linux.cpp,v 1.1 2019/11/17 16:19:57 nia Exp $

Support NetBSD.

--- src/openrct2/platform/Linux.cpp.orig	2019-10-28 20:18:47.000000000 +0000
+++ src/openrct2/platform/Linux.cpp
@@ -11,7 +11,7 @@
 
 // Despite the name, this file contains support for more OSs besides Linux, provided the necessary ifdefs remain small.
 // Otherwise, they should be spun off into their own files.
-#if (defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)) && !defined(__ANDROID__)
+#if (defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)) && !defined(__ANDROID__)
 
 #    ifdef __FreeBSD__
 #        include <sys/sysctl.h>
