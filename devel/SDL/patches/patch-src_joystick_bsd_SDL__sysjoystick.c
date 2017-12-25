$NetBSD: patch-src_joystick_bsd_SDL__sysjoystick.c,v 1.6 2017/12/25 00:18:39 ryoon Exp $

--- src/joystick/bsd/SDL_sysjoystick.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/joystick/bsd/SDL_sysjoystick.c
@@ -46,6 +46,12 @@
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
@@ -77,7 +83,7 @@
 #include "../SDL_sysjoystick.h"
 #include "../SDL_joystick_c.h"
 
-#define MAX_UHID_JOYS	4
+#define MAX_UHID_JOYS	64
 #define MAX_JOY_JOYS	2
 #define MAX_JOYS	(MAX_UHID_JOYS + MAX_JOY_JOYS)
 
@@ -148,9 +154,11 @@ static char *joydevnames[MAX_JOYS];
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
@@ -314,6 +322,45 @@ SDL_SYS_JoystickOpen(SDL_Joystick *joy)
 #endif
 		rep->rid = -1; /* XXX */
 	}
+#if defined(__NetBSD__)
+	usb_device_descriptor_t udd;
+	struct usb_string_desc usd;
+	if (ioctl(fd, USB_GET_DEVICE_DESC, &udd) == -1) {
+		fprintf(stderr, "USB_GET_DEVICE_DESC failed: %s\n", strerror(errno));
+		goto desc_failed;
+	}
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
+	int error = ioctl(fd, USB_GET_STRING_DESC, &usd);
+	if (error != 0 && usd.usd_language_id != 0) {
+		usd.usd_language_id = 0;
+		error = ioctl(fd, USB_GET_STRING_DESC, &usd);
+	}
+	if (error == 0) {
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
@@ -386,10 +433,21 @@ SDL_SYS_JoystickOpen(SDL_Joystick *joy)
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
 
+#ifdef __NetBSD__
+	/* Flush any pending events */
+	while (read(joy->hwdata->fd, REP_BUF_DATA(rep), rep->size) == rep->size)
+		;
+#endif
+
 	return (0);
 usberr:
 	close(hw->fd);
@@ -459,63 +517,62 @@ SDL_SYS_JoystickUpdate(SDL_Joystick *joy
 	
 	rep = &joy->hwdata->inreport;
 
-	if (read(joy->hwdata->fd, REP_BUF_DATA(rep), rep->size) != rep->size) {
-		return;
-	}
+	while (read(joy->hwdata->fd, REP_BUF_DATA(rep), rep->size) == rep->size) {
 #if defined(USBHID_NEW) || (defined(__FREEBSD__) && __FreeBSD_kernel_version >= 500111) || defined(__FreeBSD_kernel__)
-	hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input, rep->rid);
+		hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input, rep->rid);
 #else
-	hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input);
+		hdata = hid_start_parse(joy->hwdata->repdesc, 1 << hid_input);
 #endif
-	if (hdata == NULL) {
-		fprintf(stderr, "%s: Cannot start HID parser\n",
-		    joy->hwdata->path);
-		return;
-	}
+		if (hdata == NULL) {
+			fprintf(stderr, "%s: Cannot start HID parser\n",
+			    joy->hwdata->path);
+			continue;
+		}
 
-	for (nbutton = 0; hid_get_item(hdata, &hitem) > 0;) {
-		switch (hitem.kind) {
-		case hid_input:
-			switch (HID_PAGE(hitem.usage)) {
-			case HUP_GENERIC_DESKTOP: {
-			    unsigned usage = HID_USAGE(hitem.usage);
-			    int joyaxe = usage_to_joyaxe(usage);
-			    if (joyaxe >= 0) {
-				naxe = joy->hwdata->axis_map[joyaxe];
-				/* scaleaxe */
-				v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
-							 &hitem);
-				v -= (hitem.logical_maximum + hitem.logical_minimum + 1)/2;
-				v *= 32768/((hitem.logical_maximum - hitem.logical_minimum + 1)/2);
-				if (v != joy->axes[naxe]) {
-				    SDL_PrivateJoystickAxis(joy, naxe, v);
+		for (nbutton = 0; hid_get_item(hdata, &hitem) > 0;) {
+			switch (hitem.kind) {
+			case hid_input:
+				switch (HID_PAGE(hitem.usage)) {
+				case HUP_GENERIC_DESKTOP: {
+				    unsigned usage = HID_USAGE(hitem.usage);
+				    int joyaxe = usage_to_joyaxe(usage);
+				    if (joyaxe >= 0) {
+					naxe = joy->hwdata->axis_map[joyaxe];
+					/* scaleaxe */
+					v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
+								 &hitem);
+					v -= (hitem.logical_maximum + hitem.logical_minimum + 1)/2;
+					v *= 32768/((hitem.logical_maximum - hitem.logical_minimum + 1)/2);
+					if (v != joy->axes[naxe]) {
+					    SDL_PrivateJoystickAxis(joy, naxe, v);
+					}
+				    } else if (usage == HUG_HAT_SWITCH) {
+					v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
+								 &hitem);
+					SDL_PrivateJoystickHat(joy, 0,
+						hatval_to_sdl(v)-hitem.logical_minimum);
+				    }
+				    break;
 				}
-			    } else if (usage == HUG_HAT_SWITCH) {
-				v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
-							 &hitem);
-				SDL_PrivateJoystickHat(joy, 0,
-					hatval_to_sdl(v)-hitem.logical_minimum);
-			    }
-			    break;
-			}
-			case HUP_BUTTON:
-				v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
-				    &hitem);
-				if (joy->buttons[nbutton] != v) {
-					SDL_PrivateJoystickButton(joy,
-					    nbutton, v);
+				case HUP_BUTTON:
+					v = (Sint32)hid_get_data(REP_BUF_DATA(rep),
+					    &hitem);
+					if (joy->buttons[nbutton] != v) {
+						SDL_PrivateJoystickButton(joy,
+						    nbutton, v);
+					}
+					nbutton++;
+					break;
+				default:
+					continue;
 				}
-				nbutton++;
 				break;
 			default:
-				continue;
+				break;
 			}
-			break;
-		default:
-			break;
 		}
+		hid_end_parse(hdata);
 	}
-	hid_end_parse(hdata);
 
 	return;
 }
