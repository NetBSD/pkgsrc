$NetBSD: patch-src_sbservices.c,v 1.1 2026/05/02 07:01:15 vins Exp $

Avoid non freed use of malloc(). 

--- src/sbservices.c.orig	2026-05-02 06:38:40.114601070 +0000
+++ src/sbservices.c
@@ -178,7 +178,8 @@ sbservices_error_t sbservices_set_icon_s
 	}
 
 	uint32_t bytes = 0;
-	service_receive_with_timeout(client->parent->parent, malloc(4), 4, &bytes, 2000);
+	char buf[4];
+	service_receive_with_timeout(client->parent->parent, buf, 4, &bytes, 2000);
 	debug_info("setIconState response: %u", bytes);
 
 	if (dict) {
