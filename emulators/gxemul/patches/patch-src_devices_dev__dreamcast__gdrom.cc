$NetBSD: patch-src_devices_dev__dreamcast__gdrom.cc,v 1.3 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/devices/dev_dreamcast_gdrom.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/devices/dev_dreamcast_gdrom.cc
@@ -474,7 +474,7 @@ DEVICE_ACCESS(dreamcast_gdrom_dma)
 				// GDROM DMA transfer.
 				uint32_t dst = d->dma_reg[0x04 / sizeof(uint32_t)];
 				int length = d->dma_reg[0x08 / sizeof(uint32_t)];
-				fatal("[ dreamcast_gdrom_dma: Transfering %i bytes to 0x%08"PRIx32" ]\n", length, dst);
+				fatal("[ dreamcast_gdrom_dma: Transfering %i bytes to 0x%08" PRIx32 " ]\n", length, dst);
 
 				if (d->data == NULL) {
 					fatal("dreamcast_gdrom_dma: DMA transfer but d->data is NULL. TODO\n");
@@ -537,4 +537,3 @@ DEVINIT(dreamcast_gdrom)
 
 	return 1;
 }
-
