$NetBSD: patch-src_tools_singlejar_zip__headers.h,v 1.1 2024/01/01 12:01:00 ryoon Exp $

--- src/tools/singlejar/zip_headers.h.orig	2023-11-29 01:51:37.732181412 +0000
+++ src/tools/singlejar/zip_headers.h
@@ -27,7 +27,7 @@
 
 #if defined(__linux__)
 #include <endian.h>
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #elif defined(__APPLE__) || defined(_WIN32)
 // Hopefully OSX and Windows will keep running solely on little endian CPUs, so:
