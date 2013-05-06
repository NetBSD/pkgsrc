$NetBSD: patch-sql_sql__optimizer.h,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_optimizer.h.orig	2013-05-05 20:54:46.000000000 +0000
+++ sql/sql_optimizer.h
@@ -433,7 +433,7 @@ public:
     result= result_arg;
     lock= thd_arg->lock;
     select_lex= 0; //for safety
-    select_distinct= test(select_options & SELECT_DISTINCT);
+    select_distinct= my_test(select_options & SELECT_DISTINCT);
     no_order= 0;
     simple_order= 0;
     simple_group= 0;
