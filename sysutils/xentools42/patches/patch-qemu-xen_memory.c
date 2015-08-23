$NetBSD: patch-qemu-xen_memory.c,v 1.2 2015/08/23 16:17:12 spz Exp $

--- qemu-xen/memory.c.orig	2013-10-10 14:15:47.000000000 +0000
+++ qemu-xen/memory.c
@@ -237,6 +237,7 @@ static void flatview_simplify(FlatView *
     }
 }
 
+#undef read
 static void memory_region_read_accessor(void *opaque,
                                         target_phys_addr_t addr,
                                         uint64_t *value,
