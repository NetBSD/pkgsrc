$NetBSD: patch-src_lib_web_mongoose.c,v 1.3 2014/09/24 20:20:49 wiz Exp $

If _XOPEN_SOURCE is defined to 600, NetBSD does not provide strtoll
and other stuff.

--- src/lib/web/mongoose.c.orig	2014-07-22 08:14:56.000000000 +0000
+++ src/lib/web/mongoose.c
@@ -46,7 +46,7 @@
 #define _INTEGRAL_MAX_BITS 64   // Enable _stati64() on Windows
 #define _CRT_SECURE_NO_WARNINGS // Disable deprecation warning in VS2005+
 #undef WIN32_LEAN_AND_MEAN      // Let windows.h always include winsock2.h
-#define _XOPEN_SOURCE 600       // For flockfile() on Linux
+//#define _XOPEN_SOURCE 600       // For flockfile() on Linux
 #define __STDC_FORMAT_MACROS    // <inttypes.h> wants this for C++
 #define __STDC_LIMIT_MACROS     // C++ wants that for INT64_MAX
 #define _LARGEFILE_SOURCE       // Enable fseeko() and ftello() functions
