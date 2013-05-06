$NetBSD: patch-libmysqld_lib__sql.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- libmysqld/lib_sql.cc.orig	2013-05-05 21:46:06.000000000 +0000
+++ libmysqld/lib_sql.cc
@@ -337,7 +337,7 @@ static int emb_stmt_execute(MYSQL_STMT *
   thd->client_param_count= stmt->param_count;
   thd->client_params= stmt->params;
 
-  res= test(emb_advanced_command(stmt->mysql, COM_STMT_EXECUTE, 0, 0,
+  res= my_test(emb_advanced_command(stmt->mysql, COM_STMT_EXECUTE, 0, 0,
                                  header, sizeof(header), 1, stmt) ||
             emb_read_query_result(stmt->mysql));
   stmt->affected_rows= stmt->mysql->affected_rows;
