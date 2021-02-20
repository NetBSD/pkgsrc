$NetBSD: patch-hw_alpha_alpha_sys.h,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Pass 'devfn_min' argument to typhoon_init().

--- hw/alpha/alpha_sys.h.orig	2020-10-01 00:17:37.231192966 +0000
+++ hw/alpha/alpha_sys.h	2020-10-01 00:17:49.188425709 +0000
@@ -11,7 +11,7 @@
 
 
 PCIBus *typhoon_init(MemoryRegion *, ISABus **, qemu_irq *, AlphaCPU *[4],
-                     pci_map_irq_fn);
+                     pci_map_irq_fn, uint8_t devfn_min);
 
 /* alpha_pci.c.  */
 extern const MemoryRegionOps alpha_pci_ignore_ops;
