$NetBSD: patch-roms_qemu-palcode_vgaio.c,v 1.1 2021/02/20 22:55:19 ryoon Exp $

Add pci_vga_bus and pci_vga_dev globals so that the HWRPB CTB can
correctly reflect the location of the a graphics console.

--- roms/qemu-palcode/vgaio.c.orig	2020-10-04 17:12:53.089367837 +0000
+++ roms/qemu-palcode/vgaio.c	2020-10-04 17:13:21.240322169 +0000
@@ -570,6 +570,8 @@ vgahw_init(void)
 
  found:
   have_vga = 1;
+  pci_vga_bus = PCI_BUS(bdf);
+  pci_vga_dev = PCI_SLOT(bdf);
 
   vmode_g = find_vga_entry(3);
 
