$NetBSD: patch-memory.c,v 1.8 2014/01/15 18:26:20 wiz Exp $

--- memory.c.orig	2013-11-27 22:15:55.000000000 +0000
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
