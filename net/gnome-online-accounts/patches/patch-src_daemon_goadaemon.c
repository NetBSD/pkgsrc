$NetBSD: patch-src_daemon_goadaemon.c,v 1.1 2016/02/04 13:59:38 wiz Exp $

'%m' is only supported in syslog(3).
https://bugzilla.gnome.org/show_bug.cgi?id=761262

--- src/daemon/goadaemon.c.orig	2015-06-09 10:34:12.000000000 +0000
+++ src/daemon/goadaemon.c
@@ -17,6 +17,7 @@
  */
 
 #include "config.h"
+#include <errno.h>
 #include <glib/gi18n.h>
 #include <gio/gdesktopappinfo.h>
 #include <rest/rest-proxy.h>
@@ -248,7 +249,7 @@ goa_daemon_init (GoaDaemon *self)
   path = g_strdup_printf ("%s/goa-1.0", g_get_user_config_dir ());
   if (g_mkdir_with_parents (path, 0755) != 0)
     {
-      g_warning ("Error creating directory %s: %m", path);
+      g_warning ("Error creating directory %s: %s", path, strerror(errno));
     }
   g_free (path);
 
