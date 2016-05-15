$NetBSD: patch-memory.c,v 1.10 2016/05/15 01:25:15 ryoon Exp $

--- memory.c.orig	2016-05-11 15:56:12.000000000 +0000
+++ memory.c
@@ -431,7 +431,7 @@ static MemTxResult  memory_region_read_a
 {
     uint64_t tmp;
 
-    tmp = mr->ops->read(mr->opaque, addr, size);
+    tmp = (mr->ops->read)(mr->opaque, addr, size);
     if (mr->subpage) {
         trace_memory_region_subpage_read(get_cpu_index(), mr, addr, tmp, size);
     } else if (mr == &io_mem_notdirty) {
