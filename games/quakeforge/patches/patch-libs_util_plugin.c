$NetBSD: patch-libs_util_plugin.c,v 1.1 2019/07/06 22:53:24 nia Exp $

Use RTLD_LAZY on NetBSD as well as OpenBSD.

--- libs/util/plugin.c.orig	2013-01-23 03:10:55.000000000 +0000
+++ libs/util/plugin.c
@@ -122,7 +122,7 @@ pi_open_lib (const char *name, int globa
 {
 	void       *dlhand = 0;
 #ifdef HAVE_DLOPEN
-# ifdef __OpenBSD__
+# if defined(__OpenBSD__) || defined(__NetBSD__)
 	int        flags = RTLD_LAZY;
 # else
 	int        flags = RTLD_NOW;
