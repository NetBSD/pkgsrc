$NetBSD: patch-mkdep.c,v 1.1 2013/12/08 15:22:23 cheusov Exp $

For better portability
--- mkdep.c.orig	2013-10-09 17:38:38.000000000 +0300
+++ mkdep.c	2013-12-08 17:31:52.000000000 +0300
@@ -34,12 +34,6 @@
 #endif
 
 #include <sys/cdefs.h>
-#if !defined(lint)
-__COPYRIGHT("@(#) Copyright (c) 1999 The NetBSD Foundation, Inc.\
- All rights reserved.");
-__RCSID("$NetBSD: patch-mkdep.c,v 1.1 2013/12/08 15:22:23 cheusov Exp $");
-#endif /* not lint */
-
 #include <sys/mman.h>
 #include <sys/param.h>
 #include <sys/wait.h>
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
