$NetBSD: patch-plugins_symbol-db_symbol-db-engine-core.c,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- plugins/symbol-db/symbol-db-engine-core.c.orig	2013-09-29 15:14:43.000000000 +0000
+++ plugins/symbol-db/symbol-db-engine-core.c
@@ -179,13 +179,13 @@ static gint
 sdb_engine_add_new_symbol (SymbolDBEngine * dbe, const tagEntry * tag_entry,
 						   int file_defined_id, gboolean sym_update);
 
-GNUC_INLINE const GdaStatement *
+const GdaStatement *
 sdb_engine_get_statement_by_query_id (SymbolDBEngine * dbe, static_query_type query_id);
 
-GNUC_INLINE const GdaSet *
+const GdaSet *
 sdb_engine_get_query_parameters_list (SymbolDBEngine *dbe, static_query_type query_id);
 
-GNUC_INLINE gint
+gint
 sdb_engine_get_tuple_id_by_unique_name (SymbolDBEngine * dbe, static_query_type qtype,
 										gchar * param_key,
 										GValue * param_value);
