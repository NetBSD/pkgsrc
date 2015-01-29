$NetBSD: patch-qemu-xen_xen-hvm.c,v 1.1 2015/01/29 21:33:47 joerg Exp $

--- qemu-xen/xen-hvm.c.orig	2015-01-25 20:59:13.000000000 +0000
+++ qemu-xen/xen-hvm.c
@@ -528,7 +528,7 @@ static void xen_sync_dirty_bitmap(XenIOS
     for (i = 0; i < ARRAY_SIZE(bitmap); i++) {
         unsigned long map = bitmap[i];
         while (map != 0) {
-            j = ffsl(map) - 1;
+            j = __builtin_ffsl(map) - 1;
             map &= ~(1ul << j);
             memory_region_set_dirty(framebuffer,
                                     (i * width + j) * TARGET_PAGE_SIZE,
