$NetBSD: patch-xen_drivers_passthrough_vtd_x86_ats.c,v 1.1 2015/09/14 13:36:29 joerg Exp $

--- xen/drivers/passthrough/vtd/x86/ats.c.orig	2015-09-13 15:34:59.000000000 +0000
+++ xen/drivers/passthrough/vtd/x86/ats.c
@@ -286,7 +286,7 @@ int dev_invalidate_iotlb(struct iommu *i
         case DMA_TLB_GLOBAL_FLUSH:
             /* invalidate all translations: sbit=1,bit_63=0,bit[62:12]=1 */
             sbit = 1;
-            addr = (~0 << PAGE_SHIFT_4K) & 0x7FFFFFFFFFFFFFFF;
+            addr = (~0ULL << PAGE_SHIFT_4K) & 0x7FFFFFFFFFFFFFFF;
             ret |= qinval_device_iotlb(iommu, pdev->ats_queue_depth,
                                        sid, sbit, addr);
             break;
