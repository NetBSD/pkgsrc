$NetBSD: patch-include_SDL_SDL__config.h,v 1.1 2022/04/01 10:43:05 nia Exp $

Not every Unix system has alloca.h.

--- include/SDL/SDL_config.h.orig	2022-03-03 14:56:56.000000000 +0000
+++ include/SDL/SDL_config.h
@@ -59,7 +59,6 @@ has these C runtime functions available.
 stage, though. Send patches if your platform lacks something. */
 #ifndef _WIN32
 #define HAVE_LIBC 1
-#define HAVE_ALLOCA_H 1
 #define HAVE_SYS_TYPES_H 1
 #define HAVE_STDIO_H 1
 #define STDC_HEADERS 1
@@ -72,6 +71,10 @@ stage, though. Send patches if your plat
 #define HAVE_MATH_H 1
 #endif
 
+#if defined(__linux__) || defined(__sun)
+#define HAVE_ALLOCA_H 1
+#endif
+
 #if defined(__unix__) || defined(__APPLE__)
 #define HAVE_ICONV_H 1
 #define HAVE_SIGNAL_H 1
