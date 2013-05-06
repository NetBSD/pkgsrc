$NetBSD: patch-sql_sql__update.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_update.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_update.cc
@@ -222,7 +222,7 @@ int mysql_update(THD *thd,
                  ha_rows *found_return, ha_rows *updated_return)
 {
   bool		using_limit= limit != HA_POS_ERROR;
-  bool		safe_update= test(thd->variables.option_bits & OPTION_SAFE_UPDATES);
+  bool		safe_update= my_test(thd->variables.option_bits & OPTION_SAFE_UPDATES);
   bool          used_key_is_modified= FALSE, transactional_table, will_batch;
   int           res;
   int           error= 1;
