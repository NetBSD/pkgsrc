$NetBSD: patch-hald_freebsd_probing_probe-usb2-interface.c,v 1.1 2012/03/31 16:06:56 ryoon Exp $

* From FreeBSD ports repository to fix build on FreeBSD 9.0 RELEASE.

--- hald/freebsd/probing/probe-usb2-interface.c.orig	2009-08-24 12:42:29.000000000 +0000
+++ hald/freebsd/probing/probe-usb2-interface.c
@@ -58,11 +58,11 @@ main(int argc, char **argv)
   if (pbe == NULL)
     goto end;
 
-  busstr = getenv("HAL_PROP_USB_DEVICE_BUS_NUMBER");
+  busstr = getenv("HAL_PROP_USB_BUS_NUMBER");
   if (! busstr)
     goto end;
 
-  addrstr = getenv("HAL_PROP_USB_DEVICE_PORT_NUMBER");
+  addrstr = getenv("HAL_PROP_USB_PORT_NUMBER");
   if (! addrstr)
     goto end;
 
