$NetBSD: patch-src_devices_bus__pci.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/devices/bus_pci.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/devices/bus_pci.cc
@@ -1095,7 +1095,7 @@ printf("reg = 0x%x\n", reg);
 	case PCI_COMMAND_STATUS_REG:
 		if (value & PCI_COMMAND_IO_ENABLE)
 			enabled = 1;
-printf("  value = 0x%"PRIx32"\n", value);
+printf("  value = 0x%" PRIx32 "\n", value);
 		if (wdc0 != NULL)
 			wdc_set_io_enabled((struct wdc_data *) wdc0, enabled);
 		if (wdc1 != NULL)
@@ -1429,4 +1429,3 @@ PCIINIT(ati_radeon_9200_2)
 	/*  TODO  */
 	allocate_device_space(pd, 0x1000, 0x400000, &port, &memaddr);
 }
-
