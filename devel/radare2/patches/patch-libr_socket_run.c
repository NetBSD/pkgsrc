$NetBSD: patch-libr_socket_run.c,v 1.4 2019/03/26 19:29:53 ryoon Exp $

Support SunOS.

--- libr/socket/run.c.orig	2019-02-19 12:35:24.000000000 +0000
+++ libr/socket/run.c
@@ -286,7 +286,7 @@ static void restore_saved_fd(int saved, 
 #endif
 
 static int handle_redirection_proc(const char *cmd, bool in, bool out, bool err) {
-#if HAVE_PTY
+#if HAVE_PTY && !defined(__sun)
 	// use PTY to redirect I/O because pipes can be problematic in
 	// case of interactive programs.
 	int saved_stdin = dup (STDIN_FILENO);
