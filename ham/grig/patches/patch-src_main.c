$NetBSD: patch-src_main.c,v 1.1 2013/06/26 21:21:26 joerg Exp $

--- src/main.c.orig	2013-06-26 20:34:46.000000000 +0000
+++ src/main.c
@@ -177,16 +177,6 @@ main (int argc, char *argv[])
 
 	g_free (fname);
 
-
-	/* initialize threads; according to glib docs, this call will terminate
-	   the program if threads are not supported... then why doesn''t it work
-	   on FreeBSD?
-	*/
-	if (!g_thread_supported ())
-		g_thread_init (NULL);
-
-
-
 	/* decode command line arguments; this part of the code only sets the
 	   global flags and variables, whereafter we check each variable in
 	   descending priority order. This way it is easy to exit the program
