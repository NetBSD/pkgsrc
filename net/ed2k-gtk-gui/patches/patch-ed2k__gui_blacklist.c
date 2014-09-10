$NetBSD: patch-ed2k__gui_blacklist.c,v 1.1 2014/09/10 12:22:44 joerg Exp $

--- ed2k_gui/blacklist.c.orig	2014-09-09 18:26:47.000000000 +0000
+++ ed2k_gui/blacklist.c
@@ -294,7 +294,7 @@ add_to_blacklist (const guint8 *evilhash
 
 	g_return_if_fail (bli!=NULL);
 
-	g_memmove (bli->hash, evilhash, 16);
+	memmove (bli->hash, evilhash, 16);
 
 	bli->filesize = size;
 
