$NetBSD: patch-src_core_wee-command.c,v 1.1 2014/07/09 10:30:11 jperkin Exp $

Don't define _XOPEN_SOURCE past 600 on SunOS.

--- src/core/wee-command.c.orig	2014-02-09 08:52:53.000000000 +0000
+++ src/core/wee-command.c
@@ -21,7 +21,7 @@
  */
 
 /* this define is needed for strptime() (not on OpenBSD) */
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__sun)
 #define _XOPEN_SOURCE 700
 #endif
 
