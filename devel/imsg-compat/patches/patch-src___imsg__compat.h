$NetBSD: patch-src___imsg__compat.h,v 1.1 2025/07/25 20:53:51 vins Exp $

Define PATH_MAX on NetBSD.

--- src/_imsg_compat.h.orig	2024-09-04 22:07:27.000000000 +0000
+++ src/_imsg_compat.h
@@ -27,8 +27,10 @@
 #include <string.h>
 #include <unistd.h>
 
-#ifdef __linux__
+#if defined(__linux__)
 # include <linux/limits.h>
+#else if defined(__NetBSD__) 
+# include <sys/syslimits.h>
 #endif
 
 #ifndef HAVE_EXPLICIT_BZERO
