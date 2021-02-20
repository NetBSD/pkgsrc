$NetBSD: patch-roms_qemu-palcode_pci.h,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Move PCI_DEVFN(), PCI_BUS(), PCI_SLOT(), and PCI_FUNC() to pci.h.

--- roms/qemu-palcode/pci.h.orig	2020-10-04 16:48:50.267686138 +0000
+++ roms/qemu-palcode/pci.h	2020-10-04 16:49:11.064722703 +0000
@@ -60,6 +60,11 @@ extern void pci_config_maskw(int bdf, in
 
 extern int pci_next(int bdf, int *pmax);
 
+#define PCI_DEVFN(slot, func)	((((slot) & 0x1f) << 3) | ((func) & 0x07))
+#define PCI_BUS(devfn)		((devfn) >> 8)
+#define PCI_SLOT(devfn)		(((devfn) >> 3) & 0x1f)
+#define PCI_FUNC(devfn)		((devfn) & 0x07)
+
 #define foreachpci(BDF, MAX)				\
 	for (MAX = 0x0100, BDF = pci_next(0, &MAX);	\
 	     BDF >= 0;					\
