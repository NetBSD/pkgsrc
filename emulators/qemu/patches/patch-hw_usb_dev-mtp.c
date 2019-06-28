$NetBSD: patch-hw_usb_dev-mtp.c,v 1.4 2019/06/28 17:11:14 jperkin Exp $

Support NAME_MAX and compat for O_DIRECTORY.

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
@@ -614,6 +618,9 @@ static void usb_mtp_object_readdir(MTPSt
     }
     o->have_children = true;
 
+#ifndef O_DIRECTORY
+#define O_DIRECTORY	0
+#endif
     fd = open(o->path, O_DIRECTORY | O_CLOEXEC | O_NOFOLLOW);
     if (fd < 0) {
         return;
