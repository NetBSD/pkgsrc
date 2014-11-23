$NetBSD: patch-pm__config.in.h,v 1.1 2014/11/23 14:38:34 gson Exp $

--- pm_config.in.h.orig	2014-11-23 14:12:37.000000000 +0000
+++ pm_config.in.h
@@ -139,7 +139,7 @@
 
 /* #define HAVE_SETMODE */
 
-#if (defined(__GLIBC__) || defined(__GNU_LIBRARY__) || defined(__APPLE__))
+#if (defined(__GLIBC__) || defined(__GNU_LIBRARY__) || defined(__APPLE__)) || defined(__NetBSD__)
   #define HAVE_VASPRINTF 1
 #else
   #define HAVE_VASPRINTF 0
