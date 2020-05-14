$NetBSD: patch-bin_pg__repack.c,v 1.1 2020/05/14 19:10:47 joerg Exp $

--- bin/pg_repack.c.orig	2020-05-10 00:05:15.102859009 +0000
+++ bin/pg_repack.c
@@ -1176,7 +1176,7 @@ repack_one_table(repack_table *table, co
 	if (!advisory_lock(connection, buffer))
 		goto cleanup;
 
-	if (!(lock_exclusive(connection, buffer, table->lock_table, TRUE)))
+	if (!(lock_exclusive(connection, buffer, table->lock_table, true)))
 	{
 		if (no_kill_backend)
 			elog(INFO, "Skipping repack %s due to timeout", table->target_name);
@@ -1210,7 +1210,7 @@ repack_one_table(repack_table *table, co
 
 	indexres = execute(
 		"SELECT indexrelid,"
-		" repack.repack_indexdef(indexrelid, indrelid, $2, FALSE) "
+		" repack.repack_indexdef(indexrelid, indrelid, $2, false) "
 		" FROM pg_index WHERE indrelid = $1 AND indisvalid",
 		2, indexparams);
 
@@ -1483,7 +1483,7 @@ repack_one_table(repack_table *table, co
 	/* Bump our existing AccessShare lock to AccessExclusive */
 
 	if (!(lock_exclusive(conn2, utoa(table->target_oid, buffer),
-						 table->lock_table, FALSE)))
+						 table->lock_table, false)))
 	{
 		elog(WARNING, "lock_exclusive() failed in conn2 for %s",
 			 table->target_name);
@@ -1502,7 +1502,7 @@ repack_one_table(repack_table *table, co
 
 	command("BEGIN ISOLATION LEVEL READ COMMITTED", 0, NULL);
 	if (!(lock_exclusive(connection, utoa(table->target_oid, buffer),
-						 table->lock_table, FALSE)))
+						 table->lock_table, false)))
 	{
 		elog(WARNING, "lock_exclusive() failed in connection for %s",
 			 table->target_name);
@@ -2045,7 +2045,7 @@ repack_table_indexes(PGresult *index_det
 	resetStringInfo(&sql);
 	appendStringInfo(&sql, "LOCK TABLE %s IN ACCESS EXCLUSIVE MODE",
 					 table_name);
-	if (!(lock_exclusive(connection, params[1], sql.data, TRUE)))
+	if (!(lock_exclusive(connection, params[1], sql.data, true)))
 	{
 		elog(WARNING, "lock_exclusive() failed in connection for %s",
 			 table_name);
