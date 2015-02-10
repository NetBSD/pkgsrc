$NetBSD: patch-src_common.h,v 1.2 2015/02/10 03:30:03 rxg Exp $

--- src/common.h.orig	2015-02-07 11:28:38.000000000 +0000
+++ src/common.h
@@ -10,7 +10,7 @@
 #include "xmp.h"
 
 #if defined(__GNUC__) || defined(__clang__)
-#if !defined(WIN32) && !defined(ANDROID) && !defined(__APPLE__) && !defined(__AMIGA__) && !defined(B_BEOS_VERSION) && !defined(__ATHEOS__) && !defined(EMSCRIPTEN) && !defined(__MINT__) 
+#if !defined(WIN32) && !defined(ANDROID) && !defined(__APPLE__) && !defined(__AMIGA__) && !defined(B_BEOS_VERSION) && !defined(__ATHEOS__) && !defined(EMSCRIPTEN) && !defined(__MINT__) && !defined(__sun)
 #define USE_VERSIONED_SYMBOLS
 #endif
 #endif
