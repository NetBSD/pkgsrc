$NetBSD: patch-include_system_libcontext.h,v 1.1 2019/06/14 15:59:32 bouyer Exp $

Add NetBSD support.

--- include/system/libcontext.h.orig	2018-07-13 19:53:52.000000000 +0000
+++ include/system/libcontext.h
@@ -22,11 +22,11 @@
 #include <stddef.h>
 
 
-#if defined(__GNUC__) || defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__GNUC__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
     #define LIBCONTEXT_COMPILER_gcc
 
-    #if defined(__linux__) || defined(__FreeBSD__)
+    #if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
     #if defined(__x86_64__) || defined(__amd64__)
         #define LIBCONTEXT_PLATFORM_linux_x86_64
         #define LIBCONTEXT_CALL_CONVENTION
