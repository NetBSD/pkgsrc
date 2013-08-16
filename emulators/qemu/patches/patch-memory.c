$NetBSD: patch-memory.c,v 1.6 2013/08/16 21:20:11 adam Exp $

Avoid conflicts with SSP read() macro in NetBSD's <ssp/unistd.h>
(PR lib/43832: ssp causes common names to be defines)

--- memory.c.orig	2013-08-15 19:56:23.000000000 +0000
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
