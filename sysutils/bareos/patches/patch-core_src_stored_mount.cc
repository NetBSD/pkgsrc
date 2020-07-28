$NetBSD: patch-core_src_stored_mount.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	when using scsi_crypto on NetBSD the
	file descriptios must be opened read/write
	as read and write scsi commands are issued
	for key management

--- core/src/stored/mount.cc.orig	2020-06-25 08:19:03.686643613 +0000
+++ core/src/stored/mount.cc
@@ -246,10 +246,14 @@ mount_next_vol:
   /*
    * Ensure the device is open
    */
-  if (dev->HasCap(CAP_STREAM)) {
-    mode = OPEN_WRITE_ONLY;
-  } else {
+  if (dev->device->drive_crypto_enabled) {
     mode = OPEN_READ_WRITE;
+  } else {
+    if (dev->HasCap(CAP_STREAM)) {
+      mode = OPEN_WRITE_ONLY;
+    } else {
+      mode = OPEN_READ_ONLY;
+    }
   }
 
   /*
