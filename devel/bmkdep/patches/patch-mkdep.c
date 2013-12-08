$NetBSD: patch-mkdep.c,v 1.2 2013/12/08 16:33:35 cheusov Exp $

For better portability
--- mkdep.c.orig	2013-10-09 17:38:38.000000000 +0300
+++ mkdep.c	2013-12-08 17:31:52.000000000 +0300
@@ -89,13 +83,13 @@
 	return (const char *)p - (const char *)0 + (char *)0;
 }
 
-__dead2 static void
+static void
 usage(void)
 {
 	(void)fprintf(stderr,
 	    "usage: %s [-aDdiopqv] [-f file] [-P prefix] [-s suffixes] "
 	    "-- [flags] file ...\n",
-	    getprogname());
+	    "bmkdep");
 	exit(EXIT_FAILURE);
 }
 
@@ -234,7 +228,6 @@
 	sl = NULL;		/* XXXGCC -Wuninitialized [sun2] */
 
 	setlocale(LC_ALL, "");
-	setprogname(argv[0]);
 
 	aflag = O_WRONLY | O_APPEND | O_CREAT | O_TRUNC;
 	dflag = 0;
