$NetBSD: patch-core_src_stored_label.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	For SCSI ioctl to work on NetBSD the device must be open for writing.

--- core/src/stored/label.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/stored/label.cc
@@ -92,7 +92,7 @@ int ReadDevVolumeLabel(DeviceControlReco
         dev->max_block_size);
 
   if (!dev->IsOpen()) {
-    if (!dev->open(dcr, OPEN_READ_ONLY)) { return VOL_IO_ERROR; }
+    if (!dev->open(dcr, OPEN_READ_WRITE)) { return VOL_IO_ERROR; }
   }
 
   dev->ClearLabeled();
