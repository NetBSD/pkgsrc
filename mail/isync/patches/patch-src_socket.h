$NetBSD: patch-src_socket.h,v 1.1 2023/05/13 08:49:27 ryoon Exp $

Fix non-critical runtime error with OpenSSL 3.
From: Upstream b6c36624f04cd388873785c0631df3f2f9ac4bf0

--- src/socket.h.orig	2021-12-03 10:56:16.000000000 +0000
+++ src/socket.h
@@ -142,6 +142,7 @@ void socket_start_tls(conn_t *conn, void
 void socket_start_deflate( conn_t *conn );
 void socket_close( conn_t *sock );
 void socket_expect_activity( conn_t *sock, int expect );
+void socket_expect_eof( conn_t *sock );
 int socket_read( conn_t *sock, char *buf, uint len ); /* never waits */
 char *socket_read_line( conn_t *sock ); /* don't free return value; never waits */
 typedef enum { KeepOwn = 0, GiveOwn } ownership_t;
