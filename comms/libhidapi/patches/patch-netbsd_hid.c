$NetBSD: patch-netbsd_hid.c,v 1.2 2026/03/17 19:13:40 tsutsui Exp $

- don't assume roothub addr is always zero (see NetBSD PR/60073)
- check iconv(3) arg type properly

--- netbsd/hid.c.orig	2025-05-18 18:25:13.000000000 +0000
+++ netbsd/hid.c
@@ -30,6 +30,10 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <iconv.h>
+#ifndef ICONV_CONST
+#define ICONV_CONST
+#endif
+
 #include <poll.h>
 
 /* NetBSD */
@@ -724,6 +728,7 @@ struct hid_device_info HID_API_EXPORT * 
 	for (size_t i = 0; i < len; i++) {
 		char devpath[USB_MAX_DEVNAMELEN];
 		int bus;
+		struct hid_device_info *prev_end;
 
 		strlcpy(devpath, "/dev/", sizeof(devpath));
 		strlcat(devpath, arr[i], sizeof(devpath));
@@ -732,7 +737,17 @@ struct hid_device_info HID_API_EXPORT * 
 		if (bus == -1)
 			continue;
 
+		/*
+		 * ehci/ohci/uhci/dwctwo etc. use 'addr 1' for root hubs
+		 * but xhci uses 'addr 0' on NetBSD.
+		 * Check addr 0 (that would be unused on other than xhci)
+		 * and then check addr 1 if there is no device at addr 0.
+		 */
+		prev_end = hed.end;
 		enumerate_usb_devices(bus, 0, hid_enumerate_callback, &hed);
+		if (hed.end == prev_end)
+			enumerate_usb_devices(bus, 1,
+			    hid_enumerate_callback, &hed);
 
 		close(bus);
 	}
@@ -1087,7 +1102,7 @@ int HID_API_EXPORT_CALL hid_get_indexed_
 	struct usb_string_desc usd;
 	usb_string_descriptor_t *str;
 	iconv_t ic;
-	const char *src;
+	ICONV_CONST char *src;
 	size_t srcleft;
 	char *dst;
 	size_t dstleft;
@@ -1131,7 +1146,7 @@ int HID_API_EXPORT_CALL hid_get_indexed_
 		return -1;
 	}
 
-	src = (const char *) str->bString;
+	src = (ICONV_CONST char *)str->bString;
 	srcleft = str->bLength - 2;
 	dst = (char *) string;
 	dstleft = sizeof(wchar_t[maxlen]);
