$NetBSD: patch-src_socket.c,v 1.5 2018/09/19 13:08:14 schmonz Exp $

Prevent mbsync from crashing, PR pkg/49784.

--- src/socket.c.orig	2017-10-01 08:42:35.000000000 +0000
+++ src/socket.c
@@ -542,8 +542,10 @@ static void
 socket_connected( conn_t *conn )
 {
 #ifdef HAVE_IPV6
-	freeaddrinfo( conn->addrs );
-	conn->addrs = 0;
+	if (conn->addrs) {
+		freeaddrinfo( conn->addrs );
+		conn->addrs = 0;
+	}
 #endif
 	conf_notifier( &conn->notify, 0, POLLIN );
 	socket_expect_read( conn, 0 );
