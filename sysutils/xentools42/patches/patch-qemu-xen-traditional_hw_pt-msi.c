$NetBSD: patch-qemu-xen-traditional_hw_pt-msi.c,v 1.2 2015/08/23 16:17:12 spz Exp $

--- qemu-xen-traditional/hw/pt-msi.c.orig	2014-01-09 12:44:42.000000000 +0000
+++ qemu-xen-traditional/hw/pt-msi.c
@@ -22,6 +22,10 @@
 #include "pt-msi.h"
 #include <sys/mman.h>
 
+#ifdef __NetBSD__
+#define MAP_LOCKED MAP_WIRED
+#endif
+
 void msi_set_enable(struct pt_dev *dev, int en)
 {
     uint16_t val = 0;
