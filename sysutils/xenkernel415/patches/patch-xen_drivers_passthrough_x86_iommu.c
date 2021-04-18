$NetBSD: patch-xen_drivers_passthrough_x86_iommu.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

Silent noisy warning

--- xen/drivers/passthrough/x86/iommu.c.orig	2020-12-08 15:28:32.000000000 +0100
+++ xen/drivers/passthrough/x86/iommu.c	2020-12-08 17:32:05.407356434 +0100
@@ -248,7 +248,7 @@
             rc = iommu_map(d, _dfn(pfn), _mfn(pfn), 1ul << PAGE_ORDER_4K,
                            IOMMUF_readable | IOMMUF_writable, &flush_flags);
 
-        if ( rc )
+        if ( rc && (!paging_mode_translate(d) || rc != -16) )
             printk(XENLOG_WARNING "%pd: identity %smapping of %lx failed: %d\n",
                    d, !paging_mode_translate(d) ? "IOMMU " : "", pfn, rc);
 
