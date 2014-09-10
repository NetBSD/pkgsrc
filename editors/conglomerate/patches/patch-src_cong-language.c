$NetBSD: patch-src_cong-language.c,v 1.1 2014/09/10 12:14:07 joerg Exp $

--- src/cong-language.c.orig	2014-09-09 18:53:09.000000000 +0000
+++ src/cong-language.c
@@ -97,7 +97,7 @@ cong_per_language_set_data_for_lang (Con
 {
 	g_return_if_fail (per_language);
 
-	return g_hash_table_insert (per_language->hash_table,
+	g_hash_table_insert (per_language->hash_table,
 				    g_strdup (language),
 				    data);
 }
