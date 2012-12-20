$NetBSD: patch-lib_loop.c,v 1.1 2012/12/20 21:55:29 joerg Exp $

--- lib/loop.c.orig	2012-12-20 14:03:34.000000000 +0000
+++ lib/loop.c
@@ -85,14 +85,15 @@ void signal_main_thread(void)
 }
 
 static int ending=0;
-void * just_end_it_now(void * ignore)
+void *just_end_it_now(void * ignore)
 {
-	if (ending) return;
+	if (ending) return NULL;
 	ending=1;
 	if (libafpclient->forced_ending_hook) 
 		libafpclient->forced_ending_hook();
 	exit_program=2;
 	signal_main_thread();
+	return NULL;
 }
 
 /*This is a hack to handle a problem where the first pthread_kill doesnt' work*/
