$NetBSD: patch-core_src_plugins_stored_scsicrypto_scsicrypto-sd.cc,v 1.1 2021/02/01 09:08:43 kardel Exp $

	The original hooks did not clear the key soon enough.
	It was possible to change media in the tape library 
	without the key being cleared causing key confusion
	when bareos operation was mixed with other library clients.
	Now the key is cleared whenever the device is closed.

--- core/src/plugins/stored/scsicrypto/scsicrypto-sd.cc.orig	2021-01-22 16:17:58.773087567 +0000
+++ core/src/plugins/stored/scsicrypto/scsicrypto-sd.cc
@@ -192,11 +192,13 @@ static bRC newPlugin(PluginContext* ctx)
    *                       of the drive.
    * bSdEventVolumeStatus - plugin callback for encryption status
    *                        of the volume loaded in the drive.
+   * bSdEventDeviceClose - clear encryption status on close to
+   *                       avoid lingering keys
    */
   bareos_core_functions->registerBareosEvents(
-      ctx, 7, bSdEventLabelRead, bSdEventLabelVerified, bSdEventLabelWrite,
+      ctx, 8, bSdEventLabelRead, bSdEventLabelVerified, bSdEventLabelWrite,
       bSdEventVolumeUnload, bSdEventReadError, bSdEventDriveStatus,
-      bSdEventVolumeStatus);
+      bSdEventDeviceClose, bSdEventVolumeStatus);
 
   return bRC_OK;
 }
@@ -243,6 +245,7 @@ static bRC handlePluginEvent(PluginConte
     case bSdEventLabelRead:
     case bSdEventLabelWrite:
     case bSdEventVolumeUnload:
+    case bSdEventDeviceClose:
       return do_clear_scsi_encryption_key(value);
     case bSdEventLabelVerified:
       return do_set_scsi_encryption_key(value);
