$NetBSD: patch-ioemu-qemu-xen_hw_pass-through.c,v 1.1 2016/12/29 23:12:23 wiz Exp $

--- ioemu-qemu-xen/hw/pass-through.c.orig	2012-05-24 16:05:23.000000000 +0200
+++ ioemu-qemu-xen/hw/pass-through.c	2012-05-24 16:06:19.000000000 +0200
@@ -84,8 +84,6 @@
  */
 
 #include "pass-through.h"
-#include "pci/header.h"
-#include "pci/pci.h"
 #include "pt-msi.h"
 #include "qemu-xen.h"
 #include "iomulti.h"
