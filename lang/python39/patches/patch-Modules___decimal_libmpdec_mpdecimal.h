$NetBSD: patch-Modules___decimal_libmpdec_mpdecimal.h,v 1.1 2020/11/12 10:58:21 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). (Original code.)

--- Modules/_decimal/libmpdec/mpdecimal.h.orig	2020-11-11 21:56:51.000000000 +0000
+++ Modules/_decimal/libmpdec/mpdecimal.h
@@ -121,6 +121,9 @@ const char *mpd_version(void);
   #elif defined(__x86_64__)
     #define CONFIG_64
     #define ASM
+  #elif defined(__aarch64__)
+    #define CONFIG_64
+    #define ANSI
   #else
     #error "unknown architecture for universal build."
   #endif
