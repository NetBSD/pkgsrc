$NetBSD: patch-src_plugins_logger_logger.c,v 1.1 2013/12/12 20:17:56 jperkin Exp $

Don't define _XOPEN_SOURCE past 600 on SunOS.

--- src/plugins/logger/logger.c.orig	2013-05-20 08:06:14.000000000 +0000
+++ src/plugins/logger/logger.c
@@ -20,7 +20,7 @@
  */
 
 /* this define is needed for strptime() (not on OpenBSD) */
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__sun)
 #define _XOPEN_SOURCE 700
 #endif
 
