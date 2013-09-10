$NetBSD: patch-main.c,v 1.1 2013/09/10 14:40:33 joerg Exp $

--- main.c.orig	2013-09-09 02:13:47.000000000 +0000
+++ main.c
@@ -301,10 +301,9 @@ main(int argc, char *argv[])
 static void
 missing_param(int argc, int nargs, const char *msg)
 {
-	const char *foo = msg;
 
 	if (argc < nargs)
-		errx(EXIT_FAILURE, foo);
+		errx(EXIT_FAILURE, "%s", msg);
 }
 
 /* find command index */
