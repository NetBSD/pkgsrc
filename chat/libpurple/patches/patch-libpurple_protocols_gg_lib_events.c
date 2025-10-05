$NetBSD: patch-libpurple_protocols_gg_lib_events.c,v 1.1 2025/10/05 16:01:15 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- libpurple/protocols/gg/lib/events.c~	2024-09-17 10:52:23.000000000 +0200
+++ libpurple/protocols/gg/lib/events.c	2025-10-05 15:10:34.843089139 +0200
@@ -874,7 +874,7 @@
 	int proxy;
 	size_t req_len;
 
-	if (sess->client_version != NULL && isdigit(sess->client_version[0]))
+	if (sess->client_version != NULL && isdigit((unsigned char)sess->client_version[0]))
 		client = gg_urlencode(sess->client_version);
 	else if (sess->protocol_version <= GG_PROTOCOL_VERSION_100)
 		client = gg_urlencode(GG_DEFAULT_CLIENT_VERSION_100);
