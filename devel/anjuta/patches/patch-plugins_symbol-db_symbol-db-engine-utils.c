$NetBSD: patch-plugins_symbol-db_symbol-db-engine-utils.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/symbol-db/symbol-db-engine-utils.c.orig	2013-09-29 15:20:45.000000000 +0000
+++ plugins/symbol-db/symbol-db-engine-utils.c
@@ -33,10 +33,10 @@ static GHashTable *pixbufs_hash = NULL;
 /*
  * extern declarations 
  */
-extern GNUC_INLINE const GdaStatement *
+extern const GdaStatement *
 sdb_engine_get_statement_by_query_id (SymbolDBEngine * dbe, static_query_type query_id);
 
-extern GNUC_INLINE const GdaSet *
+extern const GdaSet *
 sdb_engine_get_query_parameters_list (SymbolDBEngine *dbe, static_query_type query_id);
 
 /*
