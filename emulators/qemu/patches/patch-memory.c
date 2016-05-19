$NetBSD: patch-memory.c,v 1.9.6.1 2016/05/19 12:56:38 bsiegert Exp $

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
