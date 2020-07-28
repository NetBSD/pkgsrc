$NetBSD: patch-core_src_stored_acquire.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	For NetBSD SCSI ioctl to go through the device must be writable.

--- core/src/stored/acquire.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/stored/acquire.cc
@@ -283,7 +283,7 @@ bool AcquireDeviceForRead(DeviceControlR
      * it opens it. If it is a tape, it checks the volume name
      */
     Dmsg1(rdebuglevel, "stored: open vol=%s\n", dcr->VolumeName);
-    if (!dev->open(dcr, OPEN_READ_ONLY)) {
+    if (!dev->open(dcr, dev->device->drive_crypto_enabled ? OPEN_READ_WRITE : OPEN_READ_ONLY)) {
       if (!dev->poll) {
         Jmsg3(jcr, M_WARNING, 0,
               _("Read open device %s Volume \"%s\" failed: ERR=%s\n"),
