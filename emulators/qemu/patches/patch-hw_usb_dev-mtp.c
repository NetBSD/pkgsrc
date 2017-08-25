$NetBSD: patch-hw_usb_dev-mtp.c,v 1.1 2017/08/25 12:39:56 jperkin Exp $

Support NAME_MAX.

--- hw/usb/dev-mtp.c.orig	2017-04-20 14:57:00.000000000 +0000
+++ hw/usb/dev-mtp.c
@@ -26,6 +26,10 @@
 #include "hw/usb.h"
 #include "hw/usb/desc.h"
 
+#ifndef NAME_MAX
+#define NAME_MAX 255
+#endif
+
 /* ----------------------------------------------------------------------- */
 
 enum mtp_container_type {
