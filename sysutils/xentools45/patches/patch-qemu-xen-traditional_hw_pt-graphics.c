$NetBSD: patch-qemu-xen-traditional_hw_pt-graphics.c,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- qemu-xen-traditional/hw/pt-graphics.c.orig	2015-01-19 16:14:46.000000000 +0100
+++ qemu-xen-traditional/hw/pt-graphics.c	2015-01-19 16:14:51.000000000 +0100
@@ -4,8 +4,6 @@
 
 #include "pass-through.h"
 #include "pci.h"
-#include "pci/header.h"
-#include "pci/pci.h"
 
 #include <unistd.h>
 #include <sys/ioctl.h>
