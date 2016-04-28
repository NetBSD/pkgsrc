$NetBSD: patch-menu-cache-daemon_menu-cached.c,v 1.1 2016/04/28 14:57:46 youri Exp $

Fix SunOS build.

--- menu-cache-daemon/menu-cached.c.orig	2012-11-14 08:07:36.000000000 +0000
+++ menu-cache-daemon/menu-cached.c
@@ -28,6 +28,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <fcntl.h>
 #include <glib.h>
 #include <gio/gio.h>
 #include <sys/types.h>
