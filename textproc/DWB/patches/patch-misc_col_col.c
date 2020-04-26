$NetBSD: patch-misc_col_col.c,v 1.1 2020/04/26 20:23:39 rillig Exp $

Fix error message about the macro strcpy being called with wrong number
of arguments.  Further above, <string.h> is already included.

--- misc/col/col.c.orig	2015-05-17 16:28:51.000000000 +0000
+++ misc/col/col.c
@@ -29,7 +29,6 @@ int cp, lp;
 int ll, llh, mustwr;
 int pcp = 0;
 char *pgmname;
-char *strcpy();
 
 main (argc, argv)
 	int argc; char **argv;
