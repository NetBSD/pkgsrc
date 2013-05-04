$NetBSD: patch-src_freeglut__joystick.c,v 1.1 2013/05/04 14:32:20 rodent Exp $

Fix usb.h include for NetBSD.

--- src/freeglut_joystick.c.orig	2011-09-28 01:37:26.000000000 +0000
+++ src/freeglut_joystick.c
@@ -152,7 +152,11 @@
 #                include <libusbhid.h>
 #            endif
 #        endif
-#        include <legacy/dev/usb/usb.h>
+#        if defined(__NetBSD__)
+#            include <dev/usb/usb.h>
+#        else
+#            include <legacy/dev/usb/usb.h>
+#        endif
 #        include <dev/usb/usbhid.h>
 
 /* Compatibility with older usb.h revisions */
