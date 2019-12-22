$NetBSD: patch-libusb_os_netbsd__usb.c,v 1.2 2019/12/22 17:06:39 jmcneill Exp $

* Do not emit log messages from netbsd_clock_gettime as it is called from
  the logger.
* Translate EWOULDBLOCK (ugen timeouts) errors to LIBUSB_ERROR_TIMEOUT.

--- libusb/os/netbsd_usb.c.orig	2018-03-17 07:23:37.000000000 +0000
+++ libusb/os/netbsd_usb.c
@@ -493,8 +493,6 @@ netbsd_handle_transfer_completion(struct
 int
 netbsd_clock_gettime(int clkid, struct timespec *tp)
 {
-	usbi_dbg("clock %d", clkid);
-
 	if (clkid == USBI_CLOCK_REALTIME)
 		return clock_gettime(CLOCK_REALTIME, tp);
 
@@ -516,6 +514,8 @@ _errno_to_libusb(int err)
 		return (LIBUSB_ERROR_NO_DEVICE);
 	case ENOMEM:
 		return (LIBUSB_ERROR_NO_MEM);
+	case EWOULDBLOCK:
+		return (LIBUSB_ERROR_TIMEOUT);
 	}
 
 	usbi_dbg("error: %s", strerror(err));
