$NetBSD: patch-src_rspamd.c,v 1.1 2022/10/30 15:38:54 jperkin Exp $

Avoid sun define.

--- src/rspamd.c.orig	2022-10-01 14:19:21.000000000 +0000
+++ src/rspamd.c
@@ -451,7 +451,7 @@ systemd_get_socket (struct rspamd_main *
 	union {
 		struct sockaddr_storage ss;
 		struct sockaddr sa;
-		struct sockaddr_un sun;
+		struct sockaddr_un s_un;
 		struct sockaddr_in6 s6;
 	} addr_storage;
 	socklen_t slen = sizeof (addr_storage);
