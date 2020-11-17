$NetBSD: patch-Modules___decimal_libmpdec_mpdecimal.h,v 1.1 2020/11/17 19:33:26 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Modules/_decimal/libmpdec/mpdecimal.h.orig	2020-08-15 05:20:16.000000000 +0000
+++ Modules/_decimal/libmpdec/mpdecimal.h
@@ -135,6 +135,9 @@ const char *mpd_version(void);
   #elif defined(__x86_64__)
     #define CONFIG_64
     #define ASM
+  #elif defined(__aarch64__)
+    #define CONFIG_64
+    #define ANSI
   #else
     #error "unknown architecture for universal build."
   #endif
