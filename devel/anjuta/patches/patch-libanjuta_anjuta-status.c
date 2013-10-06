$NetBSD: patch-libanjuta_anjuta-status.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- libanjuta/anjuta-status.c.orig	2013-09-29 15:10:21.000000000 +0000
+++ libanjuta/anjuta-status.c
@@ -389,7 +389,7 @@ anjuta_status_set_default (AnjutaStatus 
 	str = g_string_new (NULL);
 	g_hash_table_foreach (status->priv->default_status_items, foreach_hash, str);
 	status_str = g_string_free (str, FALSE);
-	anjuta_status_set (status, status_str, NULL);
+	anjuta_status_set (status, "%s", status_str);
 	g_free (status_str);
 }
 
