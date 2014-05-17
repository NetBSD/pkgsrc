$NetBSD: patch-src_socket.c,v 1.1 2014/05/17 04:06:56 schmonz Exp $

NetBSD does not support AI_V4MAPPED.

--- src/socket.c.orig	2013-12-13 17:54:37.000000000 +0000
+++ src/socket.c
@@ -349,7 +349,11 @@ socket_connect( conn_t *sock, void (*cb)
 		memset( &hints, 0, sizeof(hints) );
 		hints.ai_family = AF_UNSPEC;
 		hints.ai_socktype = SOCK_STREAM;
+#if defined(HAVE_DECL_AI_V4MAPPED)
 		hints.ai_flags = AI_V4MAPPED | AI_ADDRCONFIG;
+#else
+		hints.ai_flags = AI_ADDRCONFIG;
+#endif
 		infon( "Resolving %s... ", conf->host );
 		if ((gaierr = getaddrinfo( conf->host, NULL, &hints, &sock->addrs ))) {
 			error( "IMAP error: Cannot resolve server '%s': %s\n", conf->host, gai_strerror( gaierr ) );
