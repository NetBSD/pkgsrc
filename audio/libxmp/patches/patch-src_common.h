$NetBSD: patch-src_common.h,v 1.3 2019/11/21 23:48:27 nia Exp $

--- src/common.h.orig	2016-10-12 10:30:03.000000000 +0000
+++ src/common.h
@@ -10,7 +10,7 @@
 #include "xmp.h"
 
 #if defined(__GNUC__) || defined(__clang__)
-#if !defined(WIN32) && !defined(__ANDROID__) && !defined(__APPLE__) && !defined(__AMIGA__) && !defined(B_BEOS_VERSION) && !defined(__ATHEOS__) && !defined(EMSCRIPTEN) && !defined(__MINT__) 
+#if !defined(WIN32) && !defined(__ANDROID__) && !defined(__APPLE__) && !defined(__AMIGA__) && !defined(B_BEOS_VERSION) && !defined(__ATHEOS__) && !defined(EMSCRIPTEN) && !defined(__MINT__) && !defined(__sun)
 #define USE_VERSIONED_SYMBOLS
 #endif
 #endif
