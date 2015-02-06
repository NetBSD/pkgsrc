$NetBSD: patch-src_joystick_bsd_SDL__sysjoystick.c,v 1.3 2015/02/06 01:27:25 jmcneill Exp $

--- src/joystick/bsd/SDL_sysjoystick.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/joystick/bsd/SDL_sysjoystick.c
@@ -77,7 +77,7 @@
 #include "../SDL_sysjoystick.h"
 #include "../SDL_joystick_c.h"
 
-#define MAX_UHID_JOYS	4
+#define MAX_UHID_JOYS	64
 #define MAX_JOY_JOYS	2
 #define MAX_JOYS	(MAX_UHID_JOYS + MAX_JOY_JOYS)
 
@@ -148,9 +148,11 @@ static char *joydevnames[MAX_JOYS];
 static int	report_alloc(struct report *, struct report_desc *, int);
 static void	report_free(struct report *);
 
-#if defined(USBHID_UCR_DATA) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) && (__FreeBSD_kernel_version >= 900000)
+#define REP_BUF_DATA(rep) ((rep)->buf->ugd_data)
+#elif defined(USBHID_UCR_DATA) || defined(__FreeBSD_kernel__)
 #define REP_BUF_DATA(rep) ((rep)->buf->ucr_data)
-#elif (defined(__FREEBSD__) && (__FreeBSD_kernel_version > 800063))
+#elif (defined(__FreeBSD__) && (__FreeBSD_kernel_version > 800063))
 #define REP_BUF_DATA(rep) ((rep)->buf->ugd_data)
 #else
 #define REP_BUF_DATA(rep) ((rep)->buf->data)
@@ -314,6 +316,38 @@ SDL_SYS_JoystickOpen(SDL_Joystick *joy)
 #endif
 		rep->rid = -1; /* XXX */
 	}
+#if defined(__NetBSD__)
+	usb_device_descriptor_t udd;
+	struct usb_string_desc usd;
+	if (ioctl(fd, USB_GET_DEVICE_DESC, &udd) == -1)
+		goto desc_failed;
+
+	/* Get default language */
+	usd.usd_string_index = USB_LANGUAGE_TABLE;
+	usd.usd_language_id = 0;
+	if (ioctl(fd, USB_GET_STRING_DESC, &usd) == -1 || usd.usd_desc.bLength < 4) {
+		usd.usd_language_id = 0;
+	} else {
+		usd.usd_language_id = UGETW(usd.usd_desc.bString[0]);
+	}
+
+	usd.usd_string_index = udd.iProduct;
+	if (ioctl(fd, USB_GET_STRING_DESC, &usd) == 0) {
+		char str[128];
+		char *new_name = NULL;
+		int i;
+		for (i = 0; i < (usd.usd_desc.bLength >> 1) - 1 && i < sizeof(str) - 1; i++) {
+			str[i] = UGETW(usd.usd_desc.bString[i]);
+		}
+		str[i] = '\0';
+		asprintf(&new_name, "%s @ %s", str, path);
+		if (new_name != NULL) {
+			free(joydevnames[joy->index]);
+			joydevnames[joy->index] = new_name;
+		}
+	}
+desc_failed:
+#endif
 	if (report_alloc(rep, hw->repdesc, REPORT_INPUT) < 0) {
 		goto usberr;
 	}
@@ -386,6 +420,11 @@ SDL_SYS_JoystickOpen(SDL_Joystick *joy)
 		if (hw->axis_map[i] > 0)
 			hw->axis_map[i] = joy->naxes++;
 
+	if (joy->naxes == 0 && joy->nbuttons == 0 && joy->nhats == 0 && joy->nballs == 0) {
+		SDL_SetError("%s: Not a joystick, ignoring", hw->path);
+		goto usberr;
+	}
+
 usbend:
 	/* The poll blocks the event thread. */
 	fcntl(fd, F_SETFL, O_NONBLOCK);
