$NetBSD: patch-src_plugins_script_script-repo.c,v 1.1 2013/12/12 20:17:56 jperkin Exp $

Don't define _XOPEN_SOURCE past 600 on SunOS.

--- src/plugins/script/script-repo.c.orig	2013-05-20 08:06:14.000000000 +0000
+++ src/plugins/script/script-repo.c
@@ -23,7 +23,7 @@
  * this define is needed for strptime()
  * but is not used for OpenBSD, it causes bug with gcrypt (see bug #37373)
  */
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__sun)
 #define _XOPEN_SOURCE 700
 #endif
 
