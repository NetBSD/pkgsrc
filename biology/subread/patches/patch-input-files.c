$NetBSD: patch-input-files.c,v 1.1 2025/01/20 17:29:59 bacon Exp $

# Use standard compiler macros

--- input-files.c.orig	2024-07-26 04:36:04.000000000 +0000
+++ input-files.c
@@ -48,7 +48,7 @@ FILE * f_subr_open(const char * fname, c
 #ifdef __MINGW32__
 		return fopen64(fname, mode);
 #else
-#if defined(__LP64__) || defined(_LP64) || defined(MACOS) 
+#if defined(__LP64__) || defined(_LP64) || defined(__APPLE__) || defined(__FreeBSD__)
 		return fopen(fname, mode);
 #else
 		return fopen64(fname, mode);
