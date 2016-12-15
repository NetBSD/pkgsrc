$NetBSD: patch-src_socket.c,v 1.4 2016/12/15 14:15:01 schmonz Exp $

Prevent mbsync from crashing, PR pkg/49784.

--- src/socket.c.orig	2015-09-27 10:13:04.000000000 +0000
+++ src/socket.c
@@ -509,7 +509,10 @@ static void
 socket_connected( conn_t *conn )
 {
 #ifdef HAVE_IPV6
-	freeaddrinfo( conn->addrs );
+	if ( conn->addrs ) {
+		freeaddrinfo( conn->addrs );
+		conn->addrs = NULL;
+	}
 #endif
 	conf_notifier( &conn->notify, 0, POLLIN );
 	conn->state = SCK_READY;
