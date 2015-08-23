$NetBSD: patch-qemu-xen-traditional_hw_pt-msi.h,v 1.2 2015/08/23 16:17:12 spz Exp $

--- qemu-xen-traditional/hw/pt-msi.h.orig	2014-01-09 12:44:42.000000000 +0000
+++ qemu-xen-traditional/hw/pt-msi.h
@@ -1,7 +1,6 @@
 #ifndef _PT_MSI_H
 #define _PT_MSI_H
 
-#include "pci/pci.h"
 #include "pass-through.h"
 
 #define  PCI_CAP_ID_MSI     0x05    /* Message Signalled Interrupts */
