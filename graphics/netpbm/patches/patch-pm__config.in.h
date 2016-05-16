$NetBSD: patch-pm__config.in.h,v 1.2 2016/05/16 21:23:31 richard Exp $

--- pm_config.in.h.orig	2014-09-08 21:53:09.000000000 +0000
+++ pm_config.in.h
@@ -139,7 +139,8 @@
 
 /* #define HAVE_SETMODE */
 
-#if (defined(__GLIBC__) || defined(__GNU_LIBRARY__) || defined(__APPLE__))
+#if (defined(__GLIBC__) || defined(__GNU_LIBRARY__) || defined(__APPLE__)) \
+	|| defined(__NetBSD__) || (defined(__SVR4) && defined (__sun))
   #define HAVE_VASPRINTF 1
 #else
   #define HAVE_VASPRINTF 0
