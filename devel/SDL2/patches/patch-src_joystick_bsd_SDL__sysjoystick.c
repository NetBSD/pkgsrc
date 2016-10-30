$NetBSD: patch-src_joystick_bsd_SDL__sysjoystick.c,v 1.5 2016/10/30 10:37:17 wiz Exp $

Move variable declarations to top, for C90.

--- src/joystick/bsd/SDL_sysjoystick.c.orig	2016-10-20 03:56:26.000000000 +0000
+++ src/joystick/bsd/SDL_sysjoystick.c
@@ -289,6 +289,10 @@ SDL_SYS_JoystickOpen(SDL_Joystick * joy,
     struct report *rep = NULL;
     int fd;
     int i;
+#if defined(__NetBSD__)
+    usb_device_descriptor_t udd;
+    struct usb_string_desc usd;
+#endif
 
     fd = open(path, O_RDONLY);
     if (fd == -1) {
@@ -338,8 +342,6 @@ SDL_SYS_JoystickOpen(SDL_Joystick * joy,
         rep->rid = -1;          /* XXX */
     }
 #if defined(__NetBSD__)
-    usb_device_descriptor_t udd;
-    struct usb_string_desc usd;
     if (ioctl(fd, USB_GET_DEVICE_DESC, &udd) == -1)
         goto desc_failed;
 
