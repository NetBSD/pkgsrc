$NetBSD: patch-libr_socket_run.c,v 1.1 2016/09/16 14:46:25 jperkin Exp $

Support SunOS.

--- libr/socket/run.c.orig	2016-05-24 23:34:34.000000000 +0000
+++ libr/socket/run.c
@@ -211,7 +211,7 @@ static void setASLR(int enabled) {
 }
 
 static int handle_redirection_proc (const char *cmd, bool in, bool out, bool err) {
-#if __UNIX__ && !__ANDROID__ && LIBC_HAVE_FORK
+#if __UNIX__ && !__ANDROID__ && LIBC_HAVE_FORK && !defined(__sun)
 	// use PTY to redirect I/O because pipes can be problematic in
 	// case of interactive programs.
 	int fdm;
