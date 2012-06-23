$NetBSD: patch-io_hpmud_musb.h,v 1.1 2012/06/23 04:50:07 schnoebe Exp $

handle libusb 1.0 being installed in a subdir in pkgsrc

--- io/hpmud/musb.h.orig	2012-06-05 09:30:15.000000000 +0000
+++ io/hpmud/musb.h
@@ -30,7 +30,7 @@
 #ifdef HAVE_LIBUSB01
 #include <usb.h>
 #else
-#include <libusb.h>
+#include <libusb-1.0/libusb.h>
 #endif
 
 #include "hpmud.h"
