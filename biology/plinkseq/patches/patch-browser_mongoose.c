$NetBSD: patch-browser_mongoose.c,v 1.1 2014/02/08 12:27:14 wiedi Exp $

not needed on sunos
--- browser/mongoose.c.orig	2011-11-17 17:17:36.000000000 +0000
+++ browser/mongoose.c
@@ -21,7 +21,9 @@
 #if defined(_WIN32)
 #define _CRT_SECURE_NO_WARNINGS // Disable deprecation warning in VS2005
 #else
+#if !defined(__sun)
 #define _XOPEN_SOURCE 600 // For flockfile() on Linux
+#endif
 #define _LARGEFILE_SOURCE // Enable 64-bit file offsets
 #define __STDC_FORMAT_MACROS // <inttypes.h> wants this for C++
 #endif
