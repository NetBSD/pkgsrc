$NetBSD: patch-rftp_domacro.c,v 1.1 2013/03/02 18:29:48 joerg Exp $

--- rftp/domacro.c.orig	1994-08-22 19:56:34.000000000 +0000
+++ rftp/domacro.c
@@ -49,9 +49,7 @@ static char sccsid[] = "@(#)domacro.c	1.
 # endif
 #endif
 
-domacro(argc, argv)
-	int argc;
-	char *argv[];
+void domacro(int argc, char *argv[])
 {
 	register int i, j;
 	register char *cp1, *cp2;
