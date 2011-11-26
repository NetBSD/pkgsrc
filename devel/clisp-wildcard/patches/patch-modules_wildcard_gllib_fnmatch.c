$NetBSD: patch-modules_wildcard_gllib_fnmatch.c,v 1.1 2011/11/26 00:05:54 hans Exp $

--- modules/wildcard/gllib/fnmatch.c.orig	2010-03-18 15:41:52.000000000 +0000
+++ modules/wildcard/gllib/fnmatch.c	2011-11-25 23:55:19.000000000 +0000
@@ -30,7 +30,9 @@
 
 #include <fnmatch.h>
 
+#if !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
 #include <alloca.h>
+#endif
 #include <assert.h>
 #include <ctype.h>
 #include <errno.h>
