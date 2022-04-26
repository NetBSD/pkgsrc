$NetBSD: patch-drivers_libhid.c,v 1.2 2022/04/26 23:28:25 gdt Exp $

As comm_driver->get_interrupt() can return larger than the buffer size,
limit the future accesses by this amount.  Bump the size of the buffer
here as returns as high as 3500 have been seen.

Not yet filed upstream.
\todo Test with 2.8.0 release and drop or file upstream.

--- drivers/libhid.c.orig	2022-04-04 12:00:53.000000000 +0000
+++ drivers/libhid.c
@@ -686,7 +686,7 @@ bool_t HIDSetItemValue(hid_dev_handle_t 
  */
 int HIDGetEvents(hid_dev_handle_t udev, HIDData_t **event, int eventsize)
 {
-	unsigned char	buf[SMALLBUF];
+	unsigned char	buf[SMALLBUF * 16]; /* XXXMRG: seen at least 8x */
 	int		itemCount = 0;
 	int		buflen, ret;
 	size_t	i, r;
@@ -758,6 +758,14 @@ int HIDGetEvents(hid_dev_handle_t udev, 
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
 	ret = file_report_buffer(reportbuf, buf, (size_t)buflen);
 	if (ret < 0) {
 		upsdebug_with_errno(1, "%s: failed to buffer report", __func__);
