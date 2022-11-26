$NetBSD: patch-drivers_usbhid-ups.c,v 1.2 2022/11/26 14:45:47 gdt Exp $

Avoid re-closing a udev that already was closed.  Avoids a double-close
that triggers a SEGV in a list-delete operation.

This may actually be the real bug for this code in libusb1.c:

static int nut_libusb_open(libusb_device_handle **udevp,
[ ... ]
#ifndef __linux__ /* SUN_LIBUSB (confirmed to work on Solaris and FreeBSD) */
	/* Causes a double free corruption in linux if device is detached! */

as the same double-free list issue occurs here.


Fixed upstream slightly differently, but essentially the same, in:
https://github.com/networkupstools/nut/commit/89dbdd1e60

--- drivers/usbhid-ups.c.orig	2022-04-26 17:03:31.000000000 -0500
+++ drivers/usbhid-ups.c	2022-11-25 01:36:52.595626560 -0600
@@ -1147,6 +1147,7 @@
 	upsdebugx(1, "upsdrv_cleanup...");
 
 	comm_driver->close(udev);
+	udev = NULL;
 	Free_ReportDesc(pDesc);
 	free_report_buffer(reportbuf);
 #ifndef SHUT_MODE
@@ -1570,8 +1571,10 @@
 	upsdebugx(4, "==================================================");
 
 	/* Try to close the previous handle */
-	if (udev)
+	if (udev) {
 		comm_driver->close(udev);
+		udev = NULL;
+	}
 
 	ret = comm_driver->open(&udev, &curDevice, subdriver_matcher, NULL);
 
