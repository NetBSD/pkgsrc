$NetBSD: patch-hw_usb_dev-mtp.c,v 1.3 2019/04/24 13:59:32 ryoon Exp $

Support NAME_MAX.

--- hw/usb/dev-mtp.c.orig	2019-04-23 18:14:46.000000000 +0000
+++ hw/usb/dev-mtp.c
@@ -26,6 +26,10 @@
 #include "desc.h"
 #include "qemu/units.h"
 
+#ifndef NAME_MAX
+#define NAME_MAX 255
+#endif
+
 /* ----------------------------------------------------------------------- */
 
 enum mtp_container_type {
