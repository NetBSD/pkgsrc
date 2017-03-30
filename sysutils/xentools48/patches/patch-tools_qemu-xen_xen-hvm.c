$NetBSD: patch-tools_qemu-xen_xen-hvm.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/qemu-xen/xen-hvm.c.orig	2016-01-06 16:42:43.000000000 +0000
+++ tools/qemu-xen/xen-hvm.c
@@ -612,7 +612,7 @@ static void xen_sync_dirty_bitmap(XenIOS
     for (i = 0; i < ARRAY_SIZE(bitmap); i++) {
         unsigned long map = bitmap[i];
         while (map != 0) {
-            j = ctzl(map);
+            j = __builtin_ctzl(map);
             map &= ~(1ul << j);
             memory_region_set_dirty(framebuffer,
                                     (i * width + j) * TARGET_PAGE_SIZE,
