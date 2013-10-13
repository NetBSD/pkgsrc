$NetBSD: patch-memory.c,v 1.7 2013/10/13 12:37:58 ryoon Exp $

--- memory.c.orig	2013-10-09 19:20:32.000000000 +0000
+++ memory.c
@@ -404,7 +404,7 @@ static void memory_region_read_accessor(
     if (mr->flush_coalesced_mmio) {
         qemu_flush_coalesced_mmio_buffer();
     }
-    tmp = mr->ops->read(mr->opaque, addr, size);
+    tmp = (*mr->ops->read)(mr->opaque, addr, size);
     trace_memory_region_ops_read(mr, addr, tmp, size);
     *value |= (tmp & mask) << shift;
 }
