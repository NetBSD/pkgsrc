$NetBSD: patch-src_main.c,v 1.1 2013/03/02 17:55:27 joerg Exp $

--- src/main.c.orig	2013-03-01 14:14:10.000000000 +0000
+++ src/main.c
@@ -107,8 +107,8 @@ int show_usage(char *argv0)
 }
 
 
-int
-do_work()
+static void
+do_work(int dummy)
 {
 	if (count != -1)
 		count--;
@@ -462,7 +462,7 @@ main(int argc,char **argv)
 		vstring[0]='\0';
 	}
 
-	signal(SIGALRM,(void *)do_work);
+	signal(SIGALRM, do_work);
 
 	/* init counters */
 #if HAVE_GMP
@@ -477,7 +477,7 @@ main(int argc,char **argv)
 	tmp = 0;
 #endif
 
-	do_work();
+	do_work(0);
 
 	while(count!=0)
 	{
