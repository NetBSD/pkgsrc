$NetBSD: patch-jdk_src_solaris_native_sun_nio_fs_GnomeFileTypeDetector.c,v 1.1 2025/10/07 15:19:26 ryoon Exp $

* Fix build with GCC 14 under NetBSD. strlen() requires string.h like Solaris and Linux.

--- jdk/src/solaris/native/sun/nio/fs/GnomeFileTypeDetector.c.orig	2025-10-07 13:59:04.460058804 +0000
+++ jdk/src/solaris/native/sun/nio/fs/GnomeFileTypeDetector.c
@@ -35,7 +35,7 @@
 #include <strings.h>
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
 #include <string.h>
 #endif
 
