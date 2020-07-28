$NetBSD: patch-core_src_stored_dir__cmd.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

	For SCSI ioctl to work on NetBSD the device must be open for writing.

--- core/src/stored/dir_cmd.cc.orig	2020-04-16 08:31:41.000000000 +0000
+++ core/src/stored/dir_cmd.cc
@@ -997,7 +997,7 @@ static bool MountCmd(JobControlRecord* j
             TryAutoloadDevice(jcr, dcr, slot, "");
           }
           /* We freed the device, so reopen it and wake any waiting threads */
-          if (!dev->open(dcr, OPEN_READ_ONLY)) {
+          if (!dev->open(dcr, dev->device->drive_crypto_enabled ? OPEN_READ_WRITE : OPEN_READ_ONLY)) {
             dir->fsend(_("3901 Unable to open device %s: ERR=%s\n"),
                        dev->print_name(), dev->bstrerror());
             if (dev->blocked() == BST_UNMOUNTED) {
@@ -1062,7 +1062,7 @@ static bool MountCmd(JobControlRecord* j
                   dev->print_name());
             }
           } else if (dev->IsTape()) {
-            if (!dev->open(dcr, OPEN_READ_ONLY)) {
+            if (!dev->open(dcr, dev->device->drive_crypto_enabled ? OPEN_READ_WRITE : OPEN_READ_ONLY)) {
               dir->fsend(_("3901 Unable to open device %s: ERR=%s\n"),
                          dev->print_name(), dev->bstrerror());
               break;
