$NetBSD: patch-qemu-xen_xen-all.c,v 1.1 2015/10/19 16:40:41 joerg Exp $

ffsl doesn't exist on NetBSD, so just force the compiler builtin.

--- qemu-xen/xen-all.c.orig	2015-10-09 22:51:02.000000000 +0000
+++ qemu-xen/xen-all.c
@@ -490,7 +490,7 @@ static int xen_sync_dirty_bitmap(XenIOSt
     for (i = 0; i < ARRAY_SIZE(bitmap); i++) {
         unsigned long map = bitmap[i];
         while (map != 0) {
-            j = ffsl(map) - 1;
+            j = __builtin_ffsl(map) - 1;
             map &= ~(1ul << j);
             target_phys_addr_t todirty = vram_offset + (i * width + j) * TARGET_PAGE_SIZE;
             xen_modified_memory(todirty, TARGET_PAGE_SIZE);
