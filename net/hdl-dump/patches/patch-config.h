$NetBSD: patch-config.h,v 1.1 2020/12/13 15:47:18 nia Exp $

Do not attempt to use stat64 and friends on not-Linux.

--- config.h.orig	2020-07-27 10:03:51.000000000 +0000
+++ config.h
@@ -25,7 +25,7 @@
 #define _CONFIG_H
 
 /* MacOS X support patch; there is more in osal_unix.c */
-#if defined (__APPLE__) || defined (__FreeBSD__)
+#if !defined(__linux__)
 #  undef _BUILD_UNIX
 #  define _BUILD_UNIX
 #  define lseek64 lseek
