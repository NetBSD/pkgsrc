$NetBSD: patch-src_common.h,v 1.1 2014/09/23 13:49:30 jperkin Exp $

Avoid versioned symbols on SunOS

--- src/common.h.orig	2014-04-05 22:49:14.000000000 +0000
+++ src/common.h
@@ -10,7 +10,7 @@
 #include "xmp.h"
 
 #if defined(__GNUC__) || defined(__clang__)
-#if !defined(WIN32) && !defined(ANDROID) && !defined(__APPLE__) && !defined(__AMIGA__) && !defined(B_BEOS_VERSION) && !defined(__ATHEOS__)
+#if !defined(WIN32) && !defined(ANDROID) && !defined(__APPLE__) && !defined(__AMIGA__) && !defined(B_BEOS_VERSION) && !defined(__ATHEOS__) && !defined(__sun)
 #define USE_VERSIONED_SYMBOLS
 #endif
 #endif
