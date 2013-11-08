$NetBSD: patch-lrzip__private.h,v 1.1 2013/11/08 21:14:02 joerg Exp $

--- lrzip_private.h.orig	2013-11-08 20:52:44.000000000 +0000
+++ lrzip_private.h
@@ -139,7 +139,7 @@ extern int errno;
 #define unlikely(x)	__builtin_expect(!!(x), 0)
 #define __maybe_unused	__attribute__((unused))
 
-#if defined(__MINGW32__) || defined(__CYGWIN__) || defined(ANDROID) || defined(__APPLE__)
+#if defined(__MINGW32__) || defined(__CYGWIN__) || defined(ANDROID) || defined(__APPLE__) || defined(__NetBSD__)
 # define ffsll __builtin_ffsll
 #endif
 
