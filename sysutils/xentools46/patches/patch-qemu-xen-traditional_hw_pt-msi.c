$NetBSD: patch-qemu-xen-traditional_hw_pt-msi.c,v 1.1.1.1 2016/07/04 07:30:53 jnemeth Exp $

--- qemu-xen-traditional/hw/pt-msi.c.orig	2014-10-06 17:50:24.000000000 +0200
+++ qemu-xen-traditional/hw/pt-msi.c	2015-01-19 13:16:38.000000000 +0100
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
