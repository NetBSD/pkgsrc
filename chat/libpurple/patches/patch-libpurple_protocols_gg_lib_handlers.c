$NetBSD: patch-libpurple_protocols_gg_lib_handlers.c,v 1.1 2025/10/05 16:01:15 wiz Exp $

Fix -Wchar-subscripts in ctype(3) functions

--- libpurple/protocols/gg/lib/handlers.c~	2024-09-17 10:52:23.000000000 +0200
+++ libpurple/protocols/gg/lib/handlers.c	2025-10-05 15:10:42.887977927 +0200
@@ -117,7 +117,7 @@
 		return -1;
 	}
 
-	if (gs->client_version != NULL && !isdigit(gs->client_version[0])) {
+	if (gs->client_version != NULL && !isdigit((unsigned char)gs->client_version[0])) {
 		client_name = "";
 		client_target = "";
 	}
@@ -314,7 +314,7 @@
 	l80.image_size = gs->image_size;
 	l80.dunno2 = 0x64;
 
-	if (gs->client_version != NULL && !isdigit(gs->client_version[0])) {
+	if (gs->client_version != NULL && !isdigit((unsigned char)gs->client_version[0])) {
 		client_name = "";
 		client_name_len = 0;
 	} else {
