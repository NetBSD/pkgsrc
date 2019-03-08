$NetBSD: patch-src_socket.c,v 1.6 2019/03/08 18:14:45 ryoon Exp $

Support SNI, from https://sourceforge.net/p/isync/isync/ci/17babc1695e82ca80d032b79e920fcb86ede2347/tree/src/socket.c?diff=f698f16967ae8341ff4b506f96b8cd5790c05d27

Prevent mbsync from crashing, PR pkg/49784.

--- src/socket.c.orig	2017-10-01 08:42:35.000000000 +0000
+++ src/socket.c
@@ -270,6 +270,8 @@ socket_start_tls( conn_t *conn, void (*c
 
 	init_wakeup( &conn->ssl_fake, ssl_fake_cb, conn );
 	conn->ssl = SSL_new( ((server_conf_t *)conn->conf)->SSLContext );
+	if (ssl_return( "set server name", conn, SSL_set_tlsext_host_name( conn->ssl, conn->conf->host ) ) < 0)
+		return;
 	SSL_set_fd( conn->ssl, conn->fd );
 	SSL_set_mode( conn->ssl, SSL_MODE_ACCEPT_MOVING_WRITE_BUFFER );
 	socket_expect_read( conn, 1 );
@@ -542,8 +544,10 @@ static void
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
