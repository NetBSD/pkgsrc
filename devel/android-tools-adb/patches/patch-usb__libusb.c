$NetBSD: patch-usb__libusb.c,v 1.1 2024/09/21 13:14:58 abs Exp $

Patch for chnages libusb interface

--- usb_libusb.c.orig	2014-10-22 00:46:49.000000000 +0000
+++ usb_libusb.c
@@ -37,7 +37,7 @@
 #define   TRACE_TAG  TRACE_USB
 #include "adb.h"
 
-static adb_mutex_t usb_lock = ADB_MUTEX_INITIALIZER;
+ADB_MUTEX_DEFINE( usb_lock );
 static libusb_context *ctx = NULL;
 
 struct usb_handle
@@ -246,8 +246,8 @@ void usb_kick(struct usb_handle *h)
 }
 
 int
-check_usb_interface(libusb_interface *interface,
-                    libusb_device_descriptor *desc,
+check_usb_interface(struct libusb_interface *interface,
+                    struct libusb_device_descriptor *desc,
                     struct usb_handle *uh)
 {    
     int e;
@@ -257,7 +257,7 @@ check_usb_interface(libusb_interface *in
         return -1;
     }
     
-    libusb_interface_descriptor *idesc = &interface->altsetting[0];
+    const struct libusb_interface_descriptor *idesc = &interface->altsetting[0];
     
     if (idesc->bNumEndpoints != 2) {
         D("check_usb_interface(): Interface have not 2 endpoints, ignoring\n");
@@ -265,7 +265,7 @@ check_usb_interface(libusb_interface *in
     }
 
     for (e = 0; e < idesc->bNumEndpoints; e++) {
-        libusb_endpoint_descriptor *edesc = &idesc->endpoint[e];
+        const struct libusb_endpoint_descriptor *edesc = &idesc->endpoint[e];
         
         if (edesc->bmAttributes != LIBUSB_TRANSFER_TYPE_BULK) {
             D("check_usb_interface(): Endpoint (%u) is not bulk (%u), ignoring\n",
@@ -304,8 +304,8 @@ check_usb_interface(libusb_interface *in
 }
 
 int
-check_usb_interfaces(libusb_config_descriptor *config,
-                     libusb_device_descriptor *desc, struct usb_handle *uh)
+check_usb_interfaces(struct libusb_config_descriptor *config,
+                     struct libusb_device_descriptor *desc, struct usb_handle *uh)
 {  
     int i;
     
@@ -382,8 +382,8 @@ check_device(libusb_device *dev) 
     int found = -1;
     char serial[256] = {0};
 
-    libusb_device_descriptor desc;
-    libusb_config_descriptor *config = NULL;
+    struct libusb_device_descriptor desc;
+    struct libusb_config_descriptor *config = NULL;
     
     int r = libusb_get_device_descriptor(dev, &desc);
 
