$NetBSD: patch-src_common.h,v 1.4 2021/11/13 10:28:27 nia Exp $

Avoid versioned symbols on SunOS to fix dependencies.

--- src/common.h.orig	2021-06-10 00:24:24.000000000 +0000
+++ src/common.h
@@ -22,7 +22,7 @@
 #endif
 
 #if (defined(__GNUC__) || defined(__clang__)) && defined(XMP_SYM_VISIBILITY)
-#if !defined(_WIN32) && !defined(__ANDROID__) && !defined(__APPLE__) && !defined(LIBXMP_AMIGA) && !defined(__MSDOS__) && !defined(B_BEOS_VERSION) && !defined(__ATHEOS__) && !defined(EMSCRIPTEN) && !defined(__MINT__)
+#if !defined(_WIN32) && !defined(__ANDROID__) && !defined(__APPLE__) && !defined(LIBXMP_AMIGA) && !defined(__MSDOS__) && !defined(B_BEOS_VERSION) && !defined(__ATHEOS__) && !defined(EMSCRIPTEN) && !defined(__MINT__) && !defined(__sun)
 #define USE_VERSIONED_SYMBOLS
 #endif
 #endif
