$NetBSD: patch-libusb_os_netbsd__usb.c,v 1.1 2019/12/22 16:49:05 jmcneill Exp $

Do not emit log messages from netbsd_clock_gettime as it is called from
the logger.

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
 
