$NetBSD: patch-darwin.c,v 1.3 2013/12/16 15:31:05 jperkin Exp $

Fix format type.

--- darwin.c.orig	2013-12-16 14:57:57.000000000 +0000
+++ darwin.c
@@ -1064,7 +1064,7 @@ int usb_os_find_devices(struct usb_bus *
     result = (*(device))->GetDeviceAddress(device, (USBDeviceAddress *)&address);
 
     if (usb_debug >= 2)
-      fprintf(stderr, "usb_os_find_devices: Found USB device at location 0x%08x\n", location);
+      fprintf(stderr, "usb_os_find_devices: Found USB device at location 0x%08x\n", (unsigned int)location);
 
     /* first byte of location appears to be associated with the device's bus */
     if (location >> 24 == bus_loc >> 24) {
@@ -1092,7 +1092,7 @@ int usb_os_find_devices(struct usb_bus *
 
       if (usb_debug >= 2)
 	fprintf(stderr, "usb_os_find_devices: Found %s on %s at location 0x%08x\n",
-		dev->filename, bus->dirname, location);
+		dev->filename, bus->dirname, (unsigned int)location);
     }
 
     /* release the device now */
