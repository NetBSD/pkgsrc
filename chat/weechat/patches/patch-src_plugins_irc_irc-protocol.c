$NetBSD: patch-src_plugins_irc_irc-protocol.c,v 1.1 2013/12/12 20:17:56 jperkin Exp $

Don't define _XOPEN_SOURCE past 600 on SunOS.

--- src/plugins/irc/irc-protocol.c.orig	2013-05-20 08:06:14.000000000 +0000
+++ src/plugins/irc/irc-protocol.c
@@ -21,7 +21,7 @@
  */
 
 /* this define is needed for strptime() (not on OpenBSD) */
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__sun)
 #define _XOPEN_SOURCE 700
 #endif
 
