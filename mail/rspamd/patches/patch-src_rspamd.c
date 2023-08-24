$NetBSD: patch-src_rspamd.c,v 1.3 2023/08/24 19:38:09 wiz Exp $

Avoid sun define.

--- src/rspamd.c.orig	2023-08-03 13:56:19.000000000 +0000
+++ src/rspamd.c
@@ -456,7 +456,7 @@ systemd_get_socket(struct rspamd_main *r
 	union {
 		struct sockaddr_storage ss;
 		struct sockaddr sa;
-		struct sockaddr_un sun;
+		struct sockaddr_un s_un;
 		struct sockaddr_in6 s6;
 	} addr_storage;
 	socklen_t slen = sizeof(addr_storage);
