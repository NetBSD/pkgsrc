$NetBSD: patch-hw_pci-host_sabre.c,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Legacy OBIO IRQs on sabre have numbers between 32 and 64, so raise
number of IRQs to 64.  Fixes PR 54310.

--- hw/pci-host/sabre.c.orig	2020-08-11 21:17:15.000000000 +0200
+++ hw/pci-host/sabre.c	2020-10-10 17:37:52.445284000 +0200
@@ -396,7 +396,7 @@
                                      pci_sabre_set_irq, pci_sabre_map_irq, s,
                                      &s->pci_mmio,
                                      &s->pci_ioport,
-                                     0, 32, TYPE_PCI_BUS);
+                                     0, 64, TYPE_PCI_BUS);
 
     pci_create_simple(phb->bus, 0, TYPE_SABRE_PCI_DEVICE);
 
