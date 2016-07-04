$NetBSD: patch-qemu-xen-traditional_hw_ide.c,v 1.1.1.1 2016/07/04 07:30:53 jnemeth Exp $

--- qemu-xen-traditional/hw/ide.c.orig	2014-01-09 13:44:42.000000000 +0100
+++ qemu-xen-traditional/hw/ide.c	2015-06-11 16:15:49.000000000 +0200
@@ -757,10 +757,15 @@
     put_le16(p + 58, oldsize >> 16);
     if (s->mult_sectors)
         put_le16(p + 59, 0x100 | s->mult_sectors);
-    put_le16(p + 60, s->nb_sectors);
-    put_le16(p + 61, s->nb_sectors >> 16);
+    if (s->nb_sectors > 0x10000000)
+	oldsize = 0x10000000; /* report only 128GB */
+    else
+	oldsize =  s->nb_sectors;
+    put_le16(p + 60, oldsize);
+    put_le16(p + 61, oldsize >> 16);
     put_le16(p + 62, 0x07); /* single word dma0-2 supported */
     put_le16(p + 63, 0x07); /* mdma0-2 supported */
+    put_le16(p + 64, 0x03); /* pio3-4 supported */
     put_le16(p + 65, 120);
     put_le16(p + 66, 120);
     put_le16(p + 67, 120);
@@ -812,13 +817,12 @@
     put_le16(p + 53, 7); /* words 64-70, 54-58, 88 valid */
     put_le16(p + 62, 7);  /* single word dma0-2 supported */
     put_le16(p + 63, 7);  /* mdma0-2 supported */
-    put_le16(p + 64, 0x3f); /* PIO modes supported */
 #else
     put_le16(p + 49, 1 << 9); /* LBA supported, no DMA */
     put_le16(p + 53, 3); /* words 64-70, 54-58 valid */
     put_le16(p + 63, 0x103); /* DMA modes XXX: may be incorrect */
-    put_le16(p + 64, 1); /* PIO modes */
 #endif
+    put_le16(p + 64, 3); /* pio3-4 supported */
     put_le16(p + 65, 0xb4); /* minimum DMA multiword tx cycle time */
     put_le16(p + 66, 0xb4); /* recommended DMA multiword tx cycle time */
     put_le16(p + 67, 0x12c); /* minimum PIO cycle time without flow control */
