$NetBSD: patch-qemu-xen-traditional_hw_piix4acpi.c,v 1.2 2015/08/23 16:17:12 spz Exp $

--- qemu-xen-traditional/hw/piix4acpi.c.orig	2014-01-09 12:44:42.000000000 +0000
+++ qemu-xen-traditional/hw/piix4acpi.c
@@ -41,8 +41,12 @@
 #define PIIX4ACPI_LOG(level, fmt, ...) do { if (level <= PIIX4ACPI_LOGLEVEL) qemu_log(fmt, ## __VA_ARGS__); } while (0)
 
 #ifdef CONFIG_PASSTHROUGH
+#ifdef __NetBSD__
+#include <pciutils/header.h>
+#else
 #include <pci/header.h>
 #endif
+#endif
 
 /* PM1a_CNT bits, as defined in the ACPI specification. */
 #define SCI_EN            (1 <<  0)
