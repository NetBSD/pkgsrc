$NetBSD: patch-ioemu-qemu-xen_hw_pt-graphics.c,v 1.1 2012/05/29 15:01:34 bouyer Exp $

--- ioemu-qemu-xen/hw/pt-graphics.c.orig	2012-05-24 16:16:49.000000000 +0200
+++ ioemu-qemu-xen/hw/pt-graphics.c	2012-05-24 16:16:55.000000000 +0200
@@ -3,8 +3,6 @@
  */
 
 #include "pass-through.h"
-#include "pci/header.h"
-#include "pci/pci.h"
 
 #include <unistd.h>
 #include <sys/ioctl.h>
