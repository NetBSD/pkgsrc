$NetBSD: patch-hald_linux_addons_addon-storage.c,v 1.1.40.1 2017/05/01 09:20:18 bsiegert Exp $

include stddef.h for size_t used in scsi/sg.h
glib2 now only allows glib.h to be included

--- hald/linux/addons/addon-storage.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/addons/addon-storage.c
@@ -32,6 +32,7 @@
 #include <linux/cdrom.h>
 #include <linux/fs.h>
 #include <mntent.h>
+#include <stddef.h>
 #include <scsi/sg.h>
 #include <stdint.h>
 #include <stdio.h>
@@ -39,7 +40,7 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
-#include <glib/gmain.h>
+#include <glib.h>
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
