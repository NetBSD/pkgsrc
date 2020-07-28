$NetBSD: patch-core_src_stored_device.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	when using scsi_crypto on NetBSD the
	file descriptios must be opened read/write
	as read and write scsi commands are issued
	for key management

--- core/src/stored/device.cc.orig	2020-06-25 07:59:33.880425717 +0000
+++ core/src/stored/device.cc
@@ -282,11 +282,16 @@ bool FirstOpenDevice(DeviceControlRecord
   }
 
   int mode;
-  if (dev->HasCap(CAP_STREAM)) {
-    mode = OPEN_WRITE_ONLY;
+  if (dev->device->drive_crypto_enabled) {
+    mode = OPEN_READ_WRITE;
   } else {
-    mode = OPEN_READ_ONLY;
+    if (dev->HasCap(CAP_STREAM)) {
+      mode = OPEN_WRITE_ONLY;
+    } else {
+      mode = OPEN_READ_ONLY;
+    }
   }
+
   Dmsg0(129, "Opening device.\n");
   if (!dev->open(dcr, mode)) {
     Emsg1(M_FATAL, 0, _("dev open failed: %s\n"), dev->errmsg);
