$NetBSD: patch-libusb_os_openbsd__usb.c,v 1.1 2012/10/08 16:54:07 dholland Exp $

--- libusb/os/openbsd_usb.c.orig    2012-04-20 06:44:27.000000000 +0000
+++ libusb/os/openbsd_usb.c
@@ -26,7 +26,11 @@
 #include <string.h>
 #include <unistd.h>
 
+#ifdef __DragonFly__
+#include <bus/usb/usb.h>
+#else
 #include <dev/usb/usb.h>
+#endif
 
 #include "libusb.h"
 #include "libusbi.h"
