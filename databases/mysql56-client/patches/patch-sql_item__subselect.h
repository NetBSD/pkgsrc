$NetBSD: patch-sql_item__subselect.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/item_subselect.h.orig	2013-05-05 20:54:13.000000000 +0000
+++ sql/item_subselect.h
@@ -433,7 +433,7 @@ public:
     if ( pushed_cond_guards)
       pushed_cond_guards[i]= v;
   }
-  bool have_guarded_conds() { return test(pushed_cond_guards); }
+  bool have_guarded_conds() { return my_test(pushed_cond_guards); }
 
   Item_in_subselect(Item * left_expr, st_select_lex *select_lex);
   Item_in_subselect()
