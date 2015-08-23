$NetBSD: patch-qemu-xen-traditional_hw_pt-graphics.c,v 1.2 2015/08/23 16:17:12 spz Exp $

--- qemu-xen-traditional/hw/pt-graphics.c.orig	2014-01-09 12:44:42.000000000 +0000
+++ qemu-xen-traditional/hw/pt-graphics.c
@@ -3,8 +3,6 @@
  */
 
 #include "pass-through.h"
-#include "pci/header.h"
-#include "pci/pci.h"
 
 #include <unistd.h>
 #include <sys/ioctl.h>
