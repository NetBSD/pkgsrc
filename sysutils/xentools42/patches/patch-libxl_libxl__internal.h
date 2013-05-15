$NetBSD: patch-libxl_libxl__internal.h,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

--- libxl/libxl_internal.h.orig	2012-12-17 15:01:09.000000000 +0000
+++ libxl/libxl_internal.h
@@ -374,7 +374,11 @@ typedef struct {
 #define PCI_FUNC(devfn)         ((devfn) & 0x07)
 #define AUTO_PHP_SLOT          0x100
 #define SYSFS_PCI_DEV          "/sys/bus/pci/devices"
+#ifdef __NetBSD__
+#define SYSFS_PCIBACK_DRIVER   "/kern/xen/pci"
+#else
 #define SYSFS_PCIBACK_DRIVER   "/sys/bus/pci/drivers/pciback"
+#endif
 #define XENSTORE_PID_FILE      "/var/run/xenstored.pid"
 
 #define PROC_PCI_NUM_RESOURCES 7
