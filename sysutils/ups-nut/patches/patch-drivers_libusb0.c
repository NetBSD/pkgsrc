$NetBSD: patch-drivers_libusb0.c,v 1.1 2022/04/26 23:28:25 gdt Exp $

--- drivers/libusb0.c.orig	2022-03-27 12:59:49.000000000 +0000
+++ drivers/libusb0.c
@@ -532,6 +532,7 @@ static int libusb_open(usb_dev_handle **
  */
 static int libusb_strerror(const int ret, const char *desc)
 {
+	/* \todo: Possibly change to >= */
 	if (ret > 0) {
 		return ret;
 	}
