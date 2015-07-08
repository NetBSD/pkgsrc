$NetBSD: patch-src_socket.c,v 1.3.2.2 2015/07/08 19:51:35 tron Exp $
Prevent mbsync from crashing, PR pkg/49784.

--- src/socket.c.orig	2015-07-04 15:47:16.000000000 +0000
+++ src/socket.c
@@ -477,7 +477,10 @@ static void
 socket_connected( conn_t *conn )
 {
 #ifdef HAVE_IPV6
-	freeaddrinfo( conn->addrs );
+	if ( conn->addrs ) {
+		freeaddrinfo( conn->addrs );
+		conn->addrs = NULL;
+	}
 #endif
 	conf_fd( conn->fd, 0, POLLIN );
 	conn->state = SCK_READY;
@@ -488,7 +491,10 @@ static void
 socket_connect_bail( conn_t *conn )
 {
 #ifdef HAVE_IPV6
-	freeaddrinfo( conn->addrs );
+	if ( conn->addrs ) {
+		freeaddrinfo( conn->addrs );
+		conn->addrs = NULL;
+	}
 #endif
 	free( conn->name );
 	conn->name = 0;
