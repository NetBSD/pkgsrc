$NetBSD: patch-include_slang.h,v 1.1 2026/09/25 01:16:09 ktnb Exp $

Consider NetBSD linux but don't require glibc features.

--- include/slang.h.orig	2026-09-23 15:02:36.129068661 +0000
+++ include/slang.h
@@ -98,7 +98,7 @@ Most applications should not need to touch this sectio
         #define SLANG_WIN32 1
     #elif defined(__ANDROID__)
         #define SLANG_ANDROID 1
-    #elif defined(__linux__) || defined(__CYGWIN__) /* note: __ANDROID__ implies __linux__ */
+    #elif defined(__NetBSD__) || defined(__linux__) || defined(__CYGWIN__) /* note: __ANDROID__ implies __linux__ */
         #define SLANG_LINUX 1
     #elif defined(__APPLE__)
         #include "TargetConditionals.h"
@@ -549,7 +549,9 @@ SLANG_COMPILE_TIME_ASSERT((SLANG_PTR_IS_64 ? 8 : 4) ==
 
 // Backtrace
 #if SLANG_LINUX_FAMILY
+    #if defined(__linux__)
     #include <features.h> // for __GLIBC__ define, if using GNU libc
+    #endif
     #if defined(__GLIBC__) || (__ANDROID_API__ >= 33)
         #define SLANG_HAS_BACKTRACE 1
     #else
