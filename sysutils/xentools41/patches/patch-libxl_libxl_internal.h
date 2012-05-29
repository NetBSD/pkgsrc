$NetBSD: patch-libxl_libxl_internal.h,v 1.1 2012/05/29 15:01:34 bouyer Exp $

--- libxl/libxl_internal.h.orig	2012-05-24 13:31:11.000000000 +0200
+++ libxl/libxl_internal.h	2012-05-24 13:31:14.000000000 +0200
@@ -109,7 +109,11 @@
 #define XC_PCI_BDF             "0x%x, 0x%x, 0x%x, 0x%x"
 #define AUTO_PHP_SLOT          0x100
 #define SYSFS_PCI_DEV          "/sys/bus/pci/devices"
+#ifdef __NetBSD__
+#define SYSFS_PCIBACK_DRIVER   "/kern/xen/pci"
+#else
 #define SYSFS_PCIBACK_DRIVER   "/sys/bus/pci/drivers/pciback"
+#endif
 #define XENSTORE_PID_FILE      "/var/run/xenstored.pid"
 
 #define PROC_PCI_NUM_RESOURCES 7
