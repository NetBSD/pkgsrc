$NetBSD: patch-drivers_libusb.c,v 1.1 2018/03/28 06:23:34 mrg Exp $

Avoid "No error" messages.

--- drivers/libusb.c.orig	2012-07-31 10:38:59.000000000 -0700
+++ drivers/libusb.c	2016-10-21 01:44:40.000000000 -0700
@@ -353,7 +353,7 @@
  */
 static int libusb_strerror(const int ret, const char *desc)
 {
-	if (ret > 0) {
+	if (ret >= 0) {
 		return ret;
 	}
 
