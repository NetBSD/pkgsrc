$NetBSD: patch-awk-proctab.c,v 1.1 2011/08/04 11:37:59 joerg Exp $

--- awk/proctab.c.orig	2011-08-03 11:53:00.000000000 +0000
+++ awk/proctab.c
@@ -179,7 +179,7 @@ Cell *(*proctab[92])(Node **, int) = {
 	nullproc,	/* NUMBER */
 	nullproc,	/* STRING */
 	nullproc,	/* REGEXPR */
-	getline,	/* GETLINE */
+	my_getline,	/* GETLINE */
 	jump,	/* RETURN */
 	split,	/* SPLIT */
 	substr,	/* SUBSTR */
