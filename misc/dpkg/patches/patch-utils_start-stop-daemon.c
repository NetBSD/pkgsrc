$NetBSD: patch-utils_start-stop-daemon.c,v 1.1 2020/04/11 11:53:43 adam Exp $

Fix for systems without SOCK_NONBLOCK.

--- utils/start-stop-daemon.c.orig	2020-04-11 11:04:32.000000000 +0000
+++ utils/start-stop-daemon.c
@@ -605,7 +605,11 @@ create_notify_socket(void)
 	int fd, rc, flags;
 
 	/* Create notification socket. */
+#ifdef SOCK_NONBLOCK
 	fd = socket(AF_UNIX, SOCK_DGRAM | SOCK_NONBLOCK, 0);
+#else
+	fd = socket(AF_UNIX, SOCK_DGRAM, 0);
+#endif
 	if (fd < 0)
 		fatale("cannot create notification socket");
 
