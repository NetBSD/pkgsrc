$NetBSD: patch-xen_drivers_passthrough_vtd_x86_ats.c,v 1.1.1.1 2016/07/04 07:25:14 jnemeth Exp $

--- xen/drivers/passthrough/vtd/x86/ats.c.orig	2015-06-22 13:41:35.000000000 +0000
+++ xen/drivers/passthrough/vtd/x86/ats.c
@@ -134,7 +134,7 @@ int dev_invalidate_iotlb(struct iommu *i
         case DMA_TLB_GLOBAL_FLUSH:
             /* invalidate all translations: sbit=1,bit_63=0,bit[62:12]=1 */
             sbit = 1;
-            addr = (~0 << PAGE_SHIFT_4K) & 0x7FFFFFFFFFFFFFFF;
+            addr = (~0ULL << PAGE_SHIFT_4K) & 0x7FFFFFFFFFFFFFFF;
             rc = qinval_device_iotlb(iommu, pdev->ats_queue_depth,
                                      sid, sbit, addr);
             break;
@@ -146,7 +146,7 @@ int dev_invalidate_iotlb(struct iommu *i
             sbit = size_order ? 1 : 0;
 
             /* clear lower bits */
-            addr &= ~0 << PAGE_SHIFT_4K;
+            addr &= ~0ULL << PAGE_SHIFT_4K;
 
             /* if sbit == 1, zero out size_order bit and set lower bits to 1 */
             if ( sbit )
