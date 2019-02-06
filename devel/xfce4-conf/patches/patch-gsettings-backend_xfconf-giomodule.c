$NetBSD: patch-gsettings-backend_xfconf-giomodule.c,v 1.1 2019/02/06 11:25:02 martin Exp $

Downgrade a critical message to warning, this may happen when loading the
module w/o intention to actually use it from the introspection compiler.

Upstream ticket https://bugzilla.xfce.org/show_bug.cgi?id=15122

--- gsettings-backend/xfconf-giomodule.c.orig	2018-10-21 12:04:21.000000000 +0200
+++ gsettings-backend/xfconf-giomodule.c	2019-02-06 11:36:27.869237116 +0100
@@ -34,9 +34,9 @@ G_MODULE_EXPORT XFCONF_EXPORT void g_io_
   GError *error = NULL;
 
   if (!xfconf_init (&error)) {
-    g_critical ("Failed to get connection to xfconfd: %s", error->message);
+    /* we could be loaded from g-ir-compiler, so do not abort */
+    g_warning ("Failed to get connection to xfconfd: %s", error->message);
     g_error_free (error);
-    return;
   }
 
   g_type_module_use(G_TYPE_MODULE(module));
