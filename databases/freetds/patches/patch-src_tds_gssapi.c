$NetBSD: patch-src_tds_gssapi.c,v 1.1 2026/02/07 18:22:48 adam Exp $

Allow build when AI_V4MAPPED is not defined (e.g. NetBSD).

--- src/tds/gssapi.c.orig	2026-02-07 18:08:56.363628916 +0000
+++ src/tds/gssapi.c
@@ -267,7 +267,11 @@ tds_gss_get_auth(TDSSOCKET * tds)
 		memset(&hints, 0, sizeof(hints));
 		hints.ai_family = AF_UNSPEC;
 		hints.ai_socktype = SOCK_STREAM;
+#ifdef AI_V4MAPPED
 		hints.ai_flags = AI_V4MAPPED|AI_ADDRCONFIG|AI_CANONNAME|AI_FQDN;
+#else
+		hints.ai_flags = AI_ADDRCONFIG|AI_CANONNAME|AI_FQDN;
+#endif
 		if (!getaddrinfo(server_name, NULL, &hints, &addrs) && addrs->ai_canonname
 		    && strchr(addrs->ai_canonname, '.') != NULL)
 			server_name = addrs->ai_canonname;
