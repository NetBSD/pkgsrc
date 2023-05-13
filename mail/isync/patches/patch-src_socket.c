$NetBSD: patch-src_socket.c,v 1.8 2023/05/13 08:49:27 ryoon Exp $

Fix non-critical runtime error with OpenSSL 3.
From: Upstream b6c36624f04cd388873785c0631df3f2f9ac4bf0

--- src/socket.c.orig	2021-12-03 10:56:16.000000000 +0000
+++ src/socket.c
@@ -810,6 +810,15 @@ socket_expect_activity( conn_t *conn, in
 		conf_wakeup( &conn->fd_timeout, expect ? conn->conf->timeout : -1 );
 }
 
+void
+socket_expect_eof( conn_t *sock )
+{
+#ifdef SSL_OP_IGNORE_UNEXPECTED_EOF  // implies HAVE_LIBSSL
+	if (sock->ssl)
+		SSL_set_options( sock->ssl, SSL_OP_IGNORE_UNEXPECTED_EOF );
+#endif
+}
+
 int
 socket_read( conn_t *conn, char *buf, uint len )
 {
