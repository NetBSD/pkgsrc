$NetBSD: patch-3rdparty_mongoose_mongoose.c,v 1.3 2015/02/10 23:29:18 wiz Exp $

If _XOPEN_SOURCE is defined to 600, NetBSD does not provide strtoll
and other stuff.

https://github.com/cesanta/mongoose/pull/466

https://github.com/mamedev/mame/pull/128

--- 3rdparty/mongoose/mongoose.c.orig	2015-01-29 13:55:43.000000000 +0000
+++ 3rdparty/mongoose/mongoose.c
@@ -48,7 +48,9 @@
 #define _INTEGRAL_MAX_BITS 64   // Enable _stati64() on Windows
 #define _CRT_SECURE_NO_WARNINGS // Disable deprecation warning in VS2005+
 #undef WIN32_LEAN_AND_MEAN      // Let windows.h always include winsock2.h
+#ifdef __Linux__
 #define _XOPEN_SOURCE 600       // For flockfile() on Linux
+#endif
 #define __STDC_FORMAT_MACROS    // <inttypes.h> wants this for C++
 #define __STDC_LIMIT_MACROS     // C++ wants that for INT64_MAX
 #ifndef _LARGEFILE_SOURCE
