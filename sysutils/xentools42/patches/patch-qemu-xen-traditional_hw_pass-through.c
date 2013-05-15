$NetBSD: patch-qemu-xen-traditional_hw_pass-through.c,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

--- qemu-xen-traditional/hw/pass-through.c.orig	2012-05-24 16:05:23.000000000 +0200
+++ qemu-xen-traditional/hw/pass-through.c	2012-05-24 16:06:19.000000000 +0200
@@ -84,8 +84,6 @@
  */
 
 #include "pass-through.h"
-#include "pci/header.h"
-#include "pci/pci.h"
 #include "pt-msi.h"
 #include "qemu-xen.h"
 #include "iomulti.h"
