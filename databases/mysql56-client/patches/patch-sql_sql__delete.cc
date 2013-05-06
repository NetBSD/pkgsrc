$NetBSD: patch-sql_sql__delete.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_delete.cc.orig	2013-04-05 12:27:18.000000000 +0000
+++ sql/sql_delete.cc
@@ -119,7 +119,7 @@ bool mysql_delete(THD *thd, TABLE_LIST *
     DBUG_RETURN(true);
 
   const_cond= (!conds || conds->const_item());
-  safe_update=test(thd->variables.option_bits & OPTION_SAFE_UPDATES);
+  safe_update=my_test(thd->variables.option_bits & OPTION_SAFE_UPDATES);
   if (safe_update && const_cond)
   {
     my_message(ER_UPDATE_WITHOUT_KEY_IN_SAFE_MODE,
