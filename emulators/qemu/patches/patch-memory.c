$NetBSD: patch-memory.c,v 1.9 2015/08/12 06:55:59 ryoon Exp $

--- memory.c.orig	2015-08-11 19:11:09.000000000 +0000
+++ memory.c
@@ -396,7 +396,7 @@ static MemTxResult  memory_region_read_a
 {
     uint64_t tmp;
 
-    tmp = mr->ops->read(mr->opaque, addr, size);
+    tmp = (mr->ops->read)(mr->opaque, addr, size);
     trace_memory_region_ops_read(mr, addr, tmp, size);
     *value |= (tmp & mask) << shift;
     return MEMTX_OK;
