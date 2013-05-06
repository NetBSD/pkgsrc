$NetBSD: patch-sql_opt__range.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/opt_range.h.orig	2013-05-05 20:54:50.000000000 +0000
+++ sql/opt_range.h
@@ -596,7 +596,7 @@ public:
   THD *thd;
   int read_keys_and_merge();
 
-  bool clustered_pk_range() { return test(pk_quick_select); }
+  bool clustered_pk_range() { return my_test(pk_quick_select); }
 
   virtual bool is_valid()
   {
