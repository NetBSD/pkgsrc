$NetBSD: patch-drivers_libusb1.c,v 1.1 2022/04/26 23:28:25 gdt Exp $

--- drivers/libusb1.c.orig	2022-03-27 12:59:49.000000000 +0000
+++ drivers/libusb1.c
@@ -599,6 +599,7 @@ static int nut_libusb_open(libusb_device
  */
 static int nut_libusb_strerror(const int ret, const char *desc)
 {
+	/* \todo: Possibly change to >= */
 	if (ret > 0) {
 		return ret;
 	}
