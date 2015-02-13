$NetBSD: patch-src_joystick_bsd_SDL__sysjoystick.c,v 1.1 2015/02/13 23:31:06 jmcneill Exp $

Skip non-joystick HID devices, and give joysticks on NetBSD a human readable
name.

--- src/joystick/bsd/SDL_sysjoystick.c.orig	2014-03-16 02:31:41.000000000 +0000
+++ src/joystick/bsd/SDL_sysjoystick.c
@@ -76,7 +76,7 @@
 #include "../SDL_sysjoystick.h"
 #include "../SDL_joystick_c.h"
 
-#define MAX_UHID_JOYS   16
+#define MAX_UHID_JOYS   64
 #define MAX_JOY_JOYS    2
 #define MAX_JOYS    (MAX_UHID_JOYS + MAX_JOY_JOYS)
 
@@ -342,6 +342,38 @@ SDL_SYS_JoystickOpen(SDL_Joystick * joy,
 #endif
         rep->rid = -1;          /* XXX */
     }
+#if defined(__NetBSD__)
+    usb_device_descriptor_t udd;
+    struct usb_string_desc usd;
+    if (ioctl(fd, USB_GET_DEVICE_DESC, &udd) == -1)
+        goto desc_failed;
+
+    /* Get default language */
+    usd.usd_string_index = USB_LANGUAGE_TABLE;
+    usd.usd_language_id = 0;
+    if (ioctl(fd, USB_GET_STRING_DESC, &usd) == -1 || usd.usd_desc.bLength < 4) {
+        usd.usd_language_id = 0;
+    } else {
+        usd.usd_language_id = UGETW(usd.usd_desc.bString[0]);
+    }
+
+    usd.usd_string_index = udd.iProduct;
+    if (ioctl(fd, USB_GET_STRING_DESC, &usd) == 0) {
+        char str[128];
+        char *new_name = NULL;
+        int i;
+        for (i = 0; i < (usd.usd_desc.bLength >> 1) - 1 && i < sizeof(str) - 1; i++) {
+            str[i] = UGETW(usd.usd_desc.bString[i]);
+        }
+        str[i] = '\0';
+        asprintf(&new_name, "%s @ %s", str, path);
+        if (new_name != NULL) {
+            free(joydevnames[SDL_SYS_numjoysticks]);
+            joydevnames[SDL_SYS_numjoysticks] = new_name;
+        }
+    }
+desc_failed:
+#endif
     if (report_alloc(rep, hw->repdesc, REPORT_INPUT) < 0) {
         goto usberr;
     }
@@ -414,6 +446,11 @@ SDL_SYS_JoystickOpen(SDL_Joystick * joy,
         if (hw->axis_map[i] > 0)
             hw->axis_map[i] = joy->naxes++;
 
+    if (joy->naxes == 0 && joy->nbuttons == 0 && joy->nhats == 0 && joy->nballs == 0) {
+        SDL_SetError("%s: Not a joystick, ignoring", hw->path);
+        goto usberr;
+    }
+
   usbend:
     /* The poll blocks the event thread. */
     fcntl(fd, F_SETFL, O_NONBLOCK);
