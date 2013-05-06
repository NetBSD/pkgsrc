$NetBSD: patch-sql_sql__admin.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_admin.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_admin.cc
@@ -1123,7 +1123,7 @@ bool Sql_cmd_repair_table::execute(THD *
   thd->enable_slow_log= opt_log_slow_admin_statements;
   res= mysql_admin_table(thd, first_table, &thd->lex->check_opt, "repair",
                          TL_WRITE, 1,
-                         test(thd->lex->check_opt.sql_flags & TT_USEFRM),
+                         my_test(thd->lex->check_opt.sql_flags & TT_USEFRM),
                          HA_OPEN_FOR_REPAIR, &prepare_for_repair,
                          &handler::ha_repair, 0);
 
