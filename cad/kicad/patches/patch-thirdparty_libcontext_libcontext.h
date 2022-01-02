$NetBSD: patch-thirdparty_libcontext_libcontext.h,v 1.1 2022/01/02 19:10:03 tnn Exp $

Add NetBSD support.

--- thirdparty/libcontext/libcontext.h.orig	2021-12-22 13:32:19.000000000 +0000
+++ thirdparty/libcontext/libcontext.h
@@ -22,13 +22,13 @@
 #include <cstdio>
 
 
-#if defined(__GNUC__) || defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__GNUC__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 
     #undef LIBCONTEXT_HAS_OWN_STACK
 
     #define LIBCONTEXT_COMPILER_gcc
 
-    #if defined(__linux__) || defined(__FreeBSD__)
+    #if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
     #if defined(__x86_64__) || defined(__amd64__)
         #define LIBCONTEXT_PLATFORM_linux_x86_64
         #define LIBCONTEXT_CALL_CONVENTION
