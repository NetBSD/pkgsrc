$NetBSD: patch-libxl_libxl__internal.h,v 1.2 2015/08/23 16:17:12 spz Exp $

--- libxl/libxl_internal.h.orig	2014-09-02 06:22:57.000000000 +0000
+++ libxl/libxl_internal.h
@@ -378,7 +378,11 @@ typedef struct {
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
