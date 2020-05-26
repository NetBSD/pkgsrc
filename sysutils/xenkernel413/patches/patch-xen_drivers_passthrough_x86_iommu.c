$NetBSD: patch-xen_drivers_passthrough_x86_iommu.c,v 1.1 2020/05/26 11:12:10 bouyer Exp $

Silent noisy warning

--- xen/drivers/passthrough/x86/iommu.c.orig	2020-05-03 22:03:37.840754709 +0200
+++ xen/drivers/passthrough/x86/iommu.c	2020-05-03 22:04:36.676914512 +0200
@@ -234,7 +234,7 @@
             rc = iommu_map(d, _dfn(pfn), _mfn(pfn), PAGE_ORDER_4K,
                            IOMMUF_readable | IOMMUF_writable, &flush_flags);
 
-        if ( rc )
+        if ( rc && (!paging_mode_translate(d) || rc != -16) )
             printk(XENLOG_WARNING "%pd: identity %smapping of %lx failed: %d\n",
                    d, !paging_mode_translate(d) ? "IOMMU " : "", pfn, rc);
 
