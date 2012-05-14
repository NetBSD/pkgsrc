$NetBSD: patch-hald_linux_addons_addon-usb-csr.c,v 1.1 2012/05/14 03:12:01 sbd Exp $

--- hald/linux/addons/addon-usb-csr.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/addons/addon-usb-csr.c
@@ -29,7 +29,7 @@
 #include <string.h>
 #include <usb.h>
 
-#include <glib/gmain.h>
+#include <glib.h>
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
