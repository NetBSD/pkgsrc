$NetBSD: patch-qemu-xen-traditional_hw_pt-msi.c,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

--- qemu-xen-traditional/hw/pt-msi.c.orig	2012-05-24 13:27:50.000000000 +0200
+++ qemu-xen-traditional/hw/pt-msi.c	2012-05-24 13:28:42.000000000 +0200
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
