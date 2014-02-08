$NetBSD: patch-browser_main.c,v 1.1 2014/02/08 12:27:14 wiedi Exp $

not needed on sunos
--- browser/main.c.orig	2011-11-17 17:17:36.000000000 +0000
+++ browser/main.c
@@ -21,8 +21,10 @@
 #if defined(_WIN32)
 #define _CRT_SECURE_NO_WARNINGS  // Disable deprecation warning in VS2005
 #else
+#if !defined(__sun)
 #define _XOPEN_SOURCE 600  // For PATH_MAX on linux
 #endif
+#endif
 
 #include <sys/stat.h>
 #include <stdio.h>
