$NetBSD: patch-sql_item__cmpfunc.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/item_cmpfunc.h.orig	2013-05-05 20:53:04.000000000 +0000
+++ sql/item_cmpfunc.h
@@ -400,7 +400,7 @@ public:
     Item_func::print_op(str, query_type);
   }
 
-  bool is_null() { return test(args[0]->is_null() || args[1]->is_null()); }
+  bool is_null() { return my_test(args[0]->is_null() || args[1]->is_null()); }
   const CHARSET_INFO *compare_collation()
   { return cmp.cmp_collation.collation; }
   void top_level_item() { abort_on_null= TRUE; }
@@ -950,7 +950,7 @@ public:
   /* Compare values number pos1 and pos2 for equality */
   bool compare_elems(uint pos1, uint pos2)
   {
-    return test(compare(collation, base + pos1*size, base + pos2*size));
+    return my_test(compare(collation, base + pos1*size, base + pos2*size));
   }
   virtual Item_result result_type()= 0;
 };
