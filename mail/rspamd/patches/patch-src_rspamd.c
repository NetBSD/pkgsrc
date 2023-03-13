$NetBSD: patch-src_rspamd.c,v 1.2 2023/03/13 11:41:57 triaxx Exp $

Avoid sun define.

--- src/rspamd.c.orig	2022-10-01 14:19:21.000000000 +0000
+++ src/rspamd.c
@@ -455,7 +455,7 @@ systemd_get_socket (struct rspamd_main *
 	union {
 		struct sockaddr_storage ss;
 		struct sockaddr sa;
-		struct sockaddr_un sun;
+		struct sockaddr_un s_un;
 		struct sockaddr_in6 s6;
 	} addr_storage;
 	socklen_t slen = sizeof (addr_storage);
