$NetBSD: patch-ext_sockets_sockaddr__conv.c,v 1.1 2013/10/15 15:46:37 taca Exp $

Not all operating system have AI_V4MAPPED.

--- ext/sockets/sockaddr_conv.c.orig	2013-09-18 13:08:04.000000000 +0000
+++ ext/sockets/sockaddr_conv.c
@@ -24,6 +24,10 @@ int php_set_inet6_addr(struct sockaddr_i
 	} else {
 #if HAVE_GETADDRINFO
 
+#ifndef AI_V4MAPPED
+#define AI_V4MAPPED 0
+#endif
+
 		memset(&hints, 0, sizeof(struct addrinfo));
 		hints.ai_family = AF_INET6;
 		hints.ai_flags = AI_V4MAPPED | AI_ADDRCONFIG;
