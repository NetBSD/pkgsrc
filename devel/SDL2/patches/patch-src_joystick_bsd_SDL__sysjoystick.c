$NetBSD: patch-src_joystick_bsd_SDL__sysjoystick.c,v 1.6.14.1 2019/08/10 13:24:56 bsiegert Exp $

Move variable declarations to top, for C90.

--- src/joystick/bsd/SDL_sysjoystick.c.orig	2019-07-25 04:32:36.000000000 +0000
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
