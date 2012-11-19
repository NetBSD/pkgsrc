$NetBSD: patch-src_tuplespace.c,v 1.1 2012/11/19 03:01:07 joerg Exp $

--- src/tuplespace.c.orig	2012-11-19 01:13:47.000000000 +0000
+++ src/tuplespace.c
@@ -285,7 +285,7 @@ TupleResult
 tuplespace_enter(Tuple * tuple, GTimeVal * end_time)
 {
   TupleSlot * slot;
-  g_return_if_fail (tuple);
+  g_return_val_if_fail (tuple, TUPLE_HOLD);
   
   slot = &(tuplespace[tuple->hash]);
   return (TupleResult)tuple_slot_slot(slot, tuple, end_time);
