$NetBSD: patch-qemu-xen-traditional_hw_pass-through.h,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- qemu-xen-traditional/hw/pass-through.h.orig	2014-10-06 17:50:24.000000000 +0200
+++ qemu-xen-traditional/hw/pass-through.h	2015-01-19 13:16:38.000000000 +0100
@@ -20,8 +20,13 @@
 
 #include "hw.h"
 #include "pci.h"
+#ifdef __NetBSD__
+#include "pciutils/header.h"
+#include "pciutils/pci.h"
+#else
 #include "pci/header.h"
 #include "pci/pci.h"
+#endif
 #include "exec-all.h"
 #include "sys-queue.h"
 #include "qemu-timer.h"
