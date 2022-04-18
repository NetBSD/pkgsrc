$NetBSD: patch-drivers_libhid.c,v 1.1 2022/04/18 19:49:18 mrg Exp $

As comm_driver->get_interrupt() can return larger than the buffer size,
limit the future accesses by this amount.  Bump the size of the buffer
here as returns as high as 3500 have been seen.

--- drivers/libhid.c.orig	2015-12-29 04:08:34.000000000 -0800
+++ drivers/libhid.c	2022-04-18 12:40:35.352022446 -0700
@@ -477,7 +477,7 @@
  */
 int HIDGetEvents(hid_dev_handle_t udev, HIDData_t **event, int eventsize)
 {
-	unsigned char	buf[SMALLBUF];
+	unsigned char	buf[SMALLBUF * 16]; /* XXXMRG: seen at least 8x */
 	int		itemCount = 0;
 	int		buflen, r, i;
 	HIDData_t	*pData;
@@ -488,6 +488,14 @@
 		return buflen;	/* propagate "error" or "no event" code */
 	}
 
+	/*
+	 * XXXMRG: Avoid accessing beyond the buffer, no idea what sort of
+	 * failure mode this is.
+	 */
+	if ((size_t)buflen > sizeof buf) {
+		buflen = sizeof buf;
+	}
+
 	r = file_report_buffer(reportbuf, buf, buflen);
 	if (r < 0) {
 		upsdebug_with_errno(1, "%s: failed to buffer report", __func__);
