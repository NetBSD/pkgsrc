$NetBSD: patch-line.c,v 1.1 2015/08/18 22:14:15 wiz Exp $

Do not add conflicting prototype for fgets(), rely on stdio.h to provide one.

--- line.c.orig	1990-02-05 20:17:17.000000000 +0000
+++ line.c
@@ -67,7 +67,6 @@ L_init_file(fnumber,fname)
 int fnumber;
 char *fname;
 {
-	extern char *fgets();
 	FILE *fp;
 	static char buf[Z_LINELEN+2];	/* +2 is to leave room for us to add
 						a newline if we need to */
