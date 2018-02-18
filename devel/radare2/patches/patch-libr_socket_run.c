$NetBSD: patch-libr_socket_run.c,v 1.2 2018/02/18 17:36:58 kamil Exp $

Support SunOS.

--- libr/socket/run.c.orig	2018-01-29 10:36:59.000000000 +0000
+++ libr/socket/run.c
@@ -278,7 +278,7 @@ static void restore_saved_fd (int saved,
 }
 
 static int handle_redirection_proc (const char *cmd, bool in, bool out, bool err) {
-#if HAVE_PTY
+#if HAVE_PTY && !defined(__sun)
 	// use PTY to redirect I/O because pipes can be problematic in
 	// case of interactive programs.
 	int saved_stdin = dup (STDIN_FILENO);
