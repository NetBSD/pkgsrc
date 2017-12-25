$NetBSD: patch-src_joystick_bsd_SDL__sysjoystick.c,v 1.6 2017/12/25 00:18:39 ryoon Exp $

Move variable declarations to top, for C90.

--- src/joystick/bsd/SDL_sysjoystick.c.orig	2017-10-23 19:27:46.000000000 +0000
+++ src/joystick/bsd/SDL_sysjoystick.c
@@ -45,6 +45,12 @@
 #ifdef __DragonFly__
 #include <bus/usb/usb.h>
 #include <bus/usb/usbhid.h>
+#elif defined(__NetBSD__)
+#include <dev/usb/usb.h>
+#include <dev/usb/usbhid.h>
+#if __NetBSD_Version__ >= 899000900
+#include <dev/hid/hid.h>
+#endif
 #else
 #include <dev/usb/usb.h>
 #include <dev/usb/usbhid.h>
@@ -291,6 +297,10 @@ SDL_SYS_JoystickOpen(SDL_Joystick * joy,
     struct report *rep = NULL;
     int fd;
     int i;
+#if defined(__NetBSD__)
+    usb_device_descriptor_t udd;
+    struct usb_string_desc usd;
+#endif
 
     fd = open(path, O_RDONLY);
     if (fd == -1) {
@@ -340,8 +350,6 @@ SDL_SYS_JoystickOpen(SDL_Joystick * joy,
         rep->rid = -1;          /* XXX */
     }
 #if defined(__NetBSD__)
-    usb_device_descriptor_t udd;
-    struct usb_string_desc usd;
     if (ioctl(fd, USB_GET_DEVICE_DESC, &udd) == -1)
         goto desc_failed;
 
