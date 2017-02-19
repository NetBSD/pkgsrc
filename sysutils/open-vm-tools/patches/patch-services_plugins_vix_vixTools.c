$NetBSD: patch-services_plugins_vix_vixTools.c,v 1.1 2017/02/19 22:45:27 wiz Exp $

Include header for struct stat.

--- services/plugins/vix/vixTools.c.orig	2016-09-29 10:07:22.000000000 +0000
+++ services/plugins/vix/vixTools.c
@@ -66,7 +66,7 @@
 #include <unistd.h>
 #endif
 
-#if defined(sun) || defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(sun) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 #include <sys/stat.h>
 #endif
 
