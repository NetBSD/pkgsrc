$NetBSD: patch-src_libusb1-glue.c,v 1.1 2020/04/03 20:15:19 nia Exp $

Don't try to unload kernel drivers on NetBSD, it doesn't work.

--- src/libusb1-glue.c.orig	2019-03-25 06:02:39.000000000 +0000
+++ src/libusb1-glue.c
@@ -1920,6 +1920,7 @@ static int init_ptp_usb(PTPParams* param
    * drivers (such as mass storage), then try to unload it to make it
    * accessible from user space.
    */
+#ifndef __NetBSD__
   if (FLAG_UNLOAD_DRIVER(ptp_usb) &&
       libusb_kernel_driver_active(device_handle, ptp_usb->interface)
   ) {
@@ -1927,6 +1928,7 @@ static int init_ptp_usb(PTPParams* param
         perror("libusb_detach_kernel_driver() failed, continuing anyway...");
       }
   }
+#endif
 
 
   /*
