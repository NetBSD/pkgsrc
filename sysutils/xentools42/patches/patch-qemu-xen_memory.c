$NetBSD: patch-qemu-xen_memory.c,v 1.1 2013/05/26 20:27:43 bouyer Exp $

--- qemu-xen/memory.c.orig	2013-05-26 20:31:37.000000000 +0200
+++ qemu-xen/memory.c	2013-05-26 20:31:22.000000000 +0200
@@ -237,6 +237,7 @@
     }
 }
 
+#undef read
 static void memory_region_read_accessor(void *opaque,
                                         target_phys_addr_t addr,
                                         uint64_t *value,
