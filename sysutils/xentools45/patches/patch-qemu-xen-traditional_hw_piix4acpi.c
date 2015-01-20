$NetBSD: patch-qemu-xen-traditional_hw_piix4acpi.c,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- qemu-xen-traditional/hw/piix4acpi.c.orig	2014-10-06 17:50:24.000000000 +0200
+++ qemu-xen-traditional/hw/piix4acpi.c	2015-01-19 13:16:38.000000000 +0100
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
