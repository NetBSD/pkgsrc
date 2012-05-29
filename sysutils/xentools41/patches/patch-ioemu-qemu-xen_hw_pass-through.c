$NetBSD: patch-ioemu-qemu-xen_hw_pass-through.c,v 1.1 2012/05/29 15:01:34 bouyer Exp $

--- /home/bouyer/pkgsrc/sysutils/xentools41/work/xen-4.1.2/tools/ioemu-qemu-xen/hw/pass-through.c.orig	2012-05-24 16:05:23.000000000 +0200
+++ /home/bouyer/pkgsrc/sysutils/xentools41/work/xen-4.1.2/tools/ioemu-qemu-xen/hw/pass-through.c	2012-05-24 16:06:19.000000000 +0200
@@ -84,8 +84,6 @@
  */
 
 #include "pass-through.h"
-#include "pci/header.h"
-#include "pci/pci.h"
 #include "pt-msi.h"
 #include "qemu-xen.h"
 #include "iomulti.h"
