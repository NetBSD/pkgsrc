$NetBSD: patch-sql_item__strfunc.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/item_strfunc.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/item_strfunc.cc
@@ -100,7 +100,7 @@ bool Item_str_func::fix_fields(THD *thd,
   bool res= Item_func::fix_fields(thd, ref);
   /*
     In Item_str_func::check_well_formed_result() we may set null_value
-    flag on the same condition as in test() below.
+    flag on the same condition as in my_test() below.
   */
   maybe_null= (maybe_null || thd->is_strict_mode());
   return res;
