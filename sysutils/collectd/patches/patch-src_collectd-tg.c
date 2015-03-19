$NetBSD: patch-src_collectd-tg.c,v 1.1 2015/03/19 13:50:30 jperkin Exp $

Don't go past _XOPEN_SOURCE=600 on SunOS.

--- src/collectd-tg.c.orig	2014-01-26 08:09:14.836391498 +0000
+++ src/collectd-tg.c
@@ -32,8 +32,12 @@
 #endif
 
 #ifndef _XOPEN_SOURCE
+#ifdef __sun
+# define _XOPEN_SOURCE 600
+#else
 # define _XOPEN_SOURCE 700
 #endif
+#endif
 
 #if !__GNUC__
 # define __attribute__(x) /**/
