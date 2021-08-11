$NetBSD: patch-core_src_stored_dev.cc,v 1.2 2021/08/11 10:24:05 kardel Exp $

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
