$NetBSD: patch-src_main.c,v 1.1 2013/07/24 20:11:40 richard Exp $

unhide variable declaration behind flock conditional.

--- src/main.c.orig	2013-03-20 11:13:35.000000000 +0000
+++ src/main.c
@@ -2367,10 +2367,10 @@ static gint prohibit_duplicate_launch(vo
 		x_display = g_strdup(g_getenv("DISPLAY"));
 
 	if (uxsock < 0) {
+		gint ret;
 #if HAVE_FLOCK
 		gchar *socket_lock;
 		gint lock_fd;
-		gint ret;
 		/* If connect failed, no other process is running.
 		 * Unlink the potentially existing socket, then
 		 * open it. This has to be done locking a temporary
