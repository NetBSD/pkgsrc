$NetBSD: patch-src_freeglut__joystick.c,v 1.3 2017/04/25 11:42:42 wiz Exp $

Fix usb.h include for NetBSD.
https://github.com/dcnieho/FreeGLUT/pull/53

--- src/fg_joystick.c.orig	2014-10-20 15:27:04.000000000 +0000
+++ src/fg_joystick.c
@@ -46,21 +46,20 @@
 
 #    ifdef HAVE_USB_JS
 #        if defined(__NetBSD__)
-/* XXX The below hack is done until freeglut's autoconf is updated. */
-#            define HAVE_USBHID_H 1
 #            ifdef HAVE_USBHID_H
 #                include <usbhid.h>
 #            else
 #                include <usb.h>
 #            endif
+#            include <dev/usb/usb.h>
 #        elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #            ifdef HAVE_USBHID_H
 #                include <usbhid.h>
 #            else
 #                include <libusbhid.h>
 #            endif
+#            include <legacy/dev/usb/usb.h>
 #        endif
-#        include <legacy/dev/usb/usb.h>
 #        include <dev/usb/usbhid.h>
 
 /* Compatibility with older usb.h revisions */
