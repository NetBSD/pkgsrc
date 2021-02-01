$NetBSD: patch-core_src_stored_dev.cc,v 1.1 2021/02/01 09:08:44 kardel Exp $

	spool.cc makes use of a ficticious temporary device that
	has .device_resource set - ~Device() did not
	verify that device_resource->dev referenced
	this instance before clearing the link.
	this leads to much confusion in the reservation code.

	to use SCSI passthru file descriptors must be opened
	READ_WRITE for scsi-crypto.

--- core/src/stored/dev.cc.orig	2020-12-16 07:46:16.000000000 +0000
+++ core/src/stored/dev.cc
@@ -635,7 +635,12 @@ bool Device::open(DeviceControlRecord* d
     return false;
   }
 
+#ifdef HAVE_NETBSD_OS
+  omode = device_resource->drive_crypto_enabled ? DeviceMode::OPEN_READ_WRITE : omode;
+#endif
+
   Dmsg1(100, "call OpenDevice mode=%s\n", mode_to_str(omode));
+
   OpenDevice(dcr, omode);
 
   /*
@@ -1278,7 +1283,11 @@ Device::~Device()
   pthread_mutex_destroy(&spool_mutex);
   // RwlDestroy(&lock);
   attached_dcrs.clear();
-  if (device_resource) { device_resource->dev = nullptr; }
+  // drop device_resource link only if it references us
+  if (device_resource && device_resource->dev == this) {
+    Dmsg1(900, "term dev: link from device_resource cleared\n");
+    device_resource->dev = nullptr;
+  }
 }
 
 bool Device::CanStealLock() const
