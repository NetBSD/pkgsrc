$NetBSD: patch-sql_item__subselect.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/item_subselect.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/item_subselect.cc
@@ -3588,7 +3588,7 @@ bool subselect_hash_sj_engine::setup(Lis
                          /* TODO:
                             the NULL byte is taken into account in
                             key_parts[part_no].store_length, so instead of
-                            cur_ref_buff + test(maybe_null), we could
+                            cur_ref_buff + my_test(maybe_null), we could
                             use that information instead.
                          */
                          cur_ref_buff + (nullable ? 1 : 0),
@@ -3697,7 +3697,7 @@ bool subselect_hash_sj_engine::exec()
       goto err; /* purecov: inspected */
 
     materialize_engine->join->exec();
-    if ((res= test(materialize_engine->join->error || thd->is_fatal_error)))
+    if ((res= my_test(materialize_engine->join->error || thd->is_fatal_error)))
       goto err;
 
     /*
