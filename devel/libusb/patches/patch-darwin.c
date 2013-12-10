$NetBSD: patch-darwin.c,v 1.1 2013/12/10 13:51:55 jperkin Exp $

Fix format type.

--- darwin.c.orig	2006-03-04 02:52:46.000000000 +0000
+++ darwin.c
@@ -1064,7 +1064,7 @@ int usb_os_find_devices(struct usb_bus *
     result = (*(device))->GetDeviceAddress(device, (USBDeviceAddress *)&address);
 
     if (usb_debug >= 2)
-      fprintf(stderr, "usb_os_find_devices: Found USB device at location 0x%08lx\n", location);
+      fprintf(stderr, "usb_os_find_devices: Found USB device at location 0x%08x\n", (unsigned int)location);
 
     /* first byte of location appears to be associated with the device's bus */
     if (location >> 24 == bus_loc >> 24) {
