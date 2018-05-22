$NetBSD: patch-menu-cache-daemon_menu-cached.c,v 1.2 2018/05/22 16:03:00 youri Exp $

Fix SunOS build.

--- menu-cache-daemon/menu-cached.c.orig	2017-11-02 18:57:27.000000000 +0000
+++ menu-cache-daemon/menu-cached.c
@@ -33,6 +33,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <fcntl.h>
 #include <glib.h>
 #include <glib/gstdio.h>
 #include <gio/gio.h>
