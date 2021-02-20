$NetBSD: patch-hw_usb_dev-mtp.c,v 1.5 2021/02/20 22:59:29 ryoon Exp $

--- hw/usb/dev-mtp.c.orig	2020-12-08 16:59:44.000000000 +0000
+++ hw/usb/dev-mtp.c
@@ -30,6 +30,10 @@
 #include "qemu/units.h"
 #include "qom/object.h"
 
+#ifndef NAME_MAX
+#define NAME_MAX 255
+#endif
+
 /* ----------------------------------------------------------------------- */
 
 enum mtp_container_type {
@@ -618,6 +622,9 @@ static void usb_mtp_object_readdir(MTPSt
     }
     o->have_children = true;
 
+#ifndef O_DIRECTORY
+#define O_DIRECTORY	0
+#endif
     fd = open(o->path, O_DIRECTORY | O_CLOEXEC | O_NOFOLLOW);
     if (fd < 0) {
         return;
