$NetBSD: patch-core_src_plugins_stored_scsicrypto-sd.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	The original hooks did not clear the key soon enough.
	It was possible to change media in the tape library 
	without the key being cleared causing key confusion
	when bareos operation was mixed with other library clients.
	Now the key is cleared whenever the device is closed.

--- core/src/plugins/stored/scsicrypto-sd.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/plugins/stored/scsicrypto-sd.cc
@@ -181,6 +181,7 @@ static bRC newPlugin(bpContext* ctx)
    * bsdEventLabelWrite - Write of volume label clear key as volume
    *                      labels are unencrypted.
    * bsdEventVolumeUnload - Unload of volume clear key
+   * bsdEventDeviceClose  - Unload of volume clear key (auto changer)
    * bsdEventReadError - Read error on volume see if its due to
    *                     the fact encryption is enabled and we
    *                     have either the wrong key loaded or no key
@@ -190,10 +191,10 @@ static bRC newPlugin(bpContext* ctx)
    * bsdEventVolumeStatus - plugin callback for encryption status
    *                        of the volume loaded in the drive.
    */
-  bfuncs->registerBareosEvents(ctx, 7, bsdEventLabelRead, bsdEventLabelVerified,
+  bfuncs->registerBareosEvents(ctx, 8, bsdEventLabelRead, bsdEventLabelVerified,
                                bsdEventLabelWrite, bsdEventVolumeUnload,
-                               bsdEventReadError, bsdEventDriveStatus,
-                               bsdEventVolumeStatus);
+                               bsdEventDeviceClose, bsdEventReadError,
+			       bsdEventDriveStatus, bsdEventVolumeStatus);
 
   return bRC_OK;
 }
@@ -240,6 +241,7 @@ static bRC handlePluginEvent(bpContext* 
     case bsdEventLabelRead:
     case bsdEventLabelWrite:
     case bsdEventVolumeUnload:
+    case bsdEventDeviceClose:
       return do_clear_scsi_encryption_key(value);
     case bsdEventLabelVerified:
       return do_set_scsi_encryption_key(value);
