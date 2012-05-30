$NetBSD: patch-ioemu-qemu-xen_hw_piix4acpi.c,v 1.1 2012/05/30 08:29:44 bouyer Exp $

--- ioemu-qemu-xen/hw/piix4acpi.c.orig	2012-05-30 10:21:32.000000000 +0200
+++ ioemu-qemu-xen/hw/piix4acpi.c	2012-05-30 10:23:11.000000000 +0200
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
