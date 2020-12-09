$NetBSD: patch-src_meta_mgvars.c,v 1.1 2020/12/09 10:48:24 nia Exp $

Don't declare own fgets.

--- src/meta/mgvars.c.orig	2004-04-10 02:54:06.000000000 +0000
+++ src/meta/mgvars.c
@@ -175,7 +175,7 @@ char  *file
 )
 {
 	FILE  *fp;
-	char  sbuf[MAXLINE], *fgets();
+	char  sbuf[MAXLINE];
 	int  inquote;
 	register char  *cp, *cp2;
 
@@ -521,7 +521,7 @@ FILE  *fp,
 register DARRAY  *dp
 )
 {
-	char  sbuf[MAXLINE], *fgets();
+	char  sbuf[MAXLINE];
 	register char  *cp;
 
 	dp->size = 0;
