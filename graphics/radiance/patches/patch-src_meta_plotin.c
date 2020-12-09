$NetBSD: patch-src_meta_plotin.c,v 1.1 2020/12/09 10:48:24 nia Exp $

Don't declare own fgets.

--- src/meta/plotin.c.orig	2003-11-15 16:51:42.000000000 +0000
+++ src/meta/plotin.c
@@ -90,7 +90,7 @@ convert(		/* convert to meta-file */
 	FILE  *infp
 )
 {
-    char  *fgets(), sbuf[BUFSIZ];
+    char  sbuf[BUFSIZ];
     int  command;
     int  a1, a2, a3, a4, a5, a6;
 
