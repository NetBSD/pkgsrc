$NetBSD: patch-ioemu-qemu-xen_hw_pt-msi.h,v 1.1 2012/05/29 15:01:34 bouyer Exp $

--- ioemu-qemu-xen/hw/pt-msi.h.orig	2012-05-24 16:09:24.000000000 +0200
+++ ioemu-qemu-xen/hw/pt-msi.h	2012-05-24 16:15:19.000000000 +0200
@@ -1,7 +1,6 @@
 #ifndef _PT_MSI_H
 #define _PT_MSI_H
 
-#include "pci/pci.h"
 #include "pass-through.h"
 
 #define  PCI_CAP_ID_MSI     0x05    /* Message Signalled Interrupts */
