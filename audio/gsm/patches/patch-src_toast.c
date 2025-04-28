$NetBSD: patch-src_toast.c,v 1.1 2025/04/28 16:16:16 tnn Exp $

Fix signal handler prototypes.

--- src/toast.c.orig	2025-04-28 16:06:28.092523246 +0000
+++ src/toast.c
@@ -211,7 +211,7 @@ static char * suffix P2((name, suf), cha
 }
 
 
-static void catch_signals P1((fun), SIGHANDLER_T (*fun) ())
+static void catch_signals P1((fun), SIGHANDLER_T (*fun) (int))
 {
 #ifdef	SIGHUP
 	signal( SIGHUP,   fun );
@@ -230,7 +230,7 @@ static void catch_signals P1((fun), SIGH
 #endif
 }
 
-static SIGHANDLER_T onintr P0()
+static SIGHANDLER_T onintr P1((signum), int signum)
 {
 	char * tmp = outname;
 
@@ -253,7 +253,7 @@ static char * emalloc P1((len), size_t l
 	if (!(s = malloc(len))) {
 		fprintf(stderr, "%s: failed to malloc %d bytes -- abort\n",
 			progname, (int)len);
-		onintr();
+		onintr(SIGTERM);
 		exit(1);
 	}
 	return s;
