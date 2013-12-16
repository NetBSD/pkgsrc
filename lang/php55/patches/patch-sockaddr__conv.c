$NetBSD: patch-sockaddr__conv.c,v 1.2.2.2 2013/12/16 17:05:48 tron Exp $

--- sockaddr_conv.c.orig	2013-10-14 13:24:02.000000000 +0000
+++ sockaddr_conv.c
@@ -26,6 +26,9 @@ int php_set_inet6_addr(struct sockaddr_i
 
 		memset(&hints, 0, sizeof(struct addrinfo));
 		hints.ai_family = AF_INET6;
+#ifndef AI_V4MAPPED
+#define AI_V4MAPPED 1
+#endif
 		hints.ai_flags = AI_V4MAPPED | AI_ADDRCONFIG;
 		getaddrinfo(string, NULL, &hints, &addrinfo);
 		if (!addrinfo) {
