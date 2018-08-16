$NetBSD: patch-hw_usb_dev-mtp.c,v 1.2 2018/08/16 10:15:09 adam Exp $

Support NAME_MAX.

--- hw/usb/dev-mtp.c.orig	2018-08-14 19:10:34.000000000 +0000
+++ hw/usb/dev-mtp.c
@@ -26,6 +26,10 @@
 #include "hw/usb.h"
 #include "desc.h"
 
+#ifndef NAME_MAX
+#define NAME_MAX 255
+#endif
+
 /* ----------------------------------------------------------------------- */
 
 enum mtp_container_type {
