$NetBSD: patch-lrzip__private.h,v 1.2 2015/06/08 14:58:09 wiedi Exp $

--- lrzip_private.h.orig	2015-03-10 09:25:42.000000000 +0000
+++ lrzip_private.h
@@ -140,7 +140,7 @@ extern int errno;
 #define unlikely(x)	__builtin_expect(!!(x), 0)
 #define __maybe_unused	__attribute__((unused))
 
-#if defined(__MINGW32__) || defined(__CYGWIN__) || defined(ANDROID) || defined(__APPLE__)
+#if defined(__MINGW32__) || defined(__CYGWIN__) || defined(ANDROID) || defined(__APPLE__) || defined(__NetBSD__)
 # define ffsll __builtin_ffsll
 #endif
 
