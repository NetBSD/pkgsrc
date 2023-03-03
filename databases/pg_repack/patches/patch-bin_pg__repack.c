$NetBSD: patch-bin_pg__repack.c,v 1.2 2023/03/03 10:51:11 adam Exp $

--- bin/pg_repack.c.orig	2020-05-10 00:05:15.102859009 +0000
+++ bin/pg_repack.c
@@ -1210,7 +1210,7 @@ repack_one_table(repack_table *table, co
 
 	indexres = execute(
 		"SELECT indexrelid,"
-		" repack.repack_indexdef(indexrelid, indrelid, $2, FALSE) "
+		" repack.repack_indexdef(indexrelid, indrelid, $2, false) "
 		" FROM pg_index WHERE indrelid = $1 AND indisvalid",
 		2, indexparams);
 
