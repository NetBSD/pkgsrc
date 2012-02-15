$NetBSD: patch-lib_src_portmixer_px__unix__oss_px__unix__oss.c,v 1.1 2012/02/15 20:01:54 hans Exp $

--- lib-src/portmixer/px_unix_oss/px_unix_oss.c.orig	2006-11-15 05:12:11.000000000 +0100
+++ lib-src/portmixer/px_unix_oss/px_unix_oss.c	2012-01-15 19:14:30.130748838 +0100
@@ -37,6 +37,8 @@
 
 #ifdef __linux__
 #include <linux/soundcard.h>
+#elif defined(__sun)
+#include <sys/soundcard.h>
 #else
 #include <machine/soundcard.h> /* JH20010905 */
 #endif
