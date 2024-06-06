$NetBSD: patch-vcl_unx_gtk3_hudawareness.cxx,v 1.1 2024/06/06 07:51:11 wiz Exp $

Fix segfault with glib2.
https://git.libreoffice.org/core/+/436f823c7c5497f2b22762cec5849a0ff84c220b%5E%21

--- vcl/unx/gtk3/hudawareness.cxx.orig	2024-06-06 07:49:03.789041452 +0000
+++ vcl/unx/gtk3/hudawareness.cxx
@@ -88,7 +88,7 @@ hud_awareness_register (GDBusConnection 
 
   if (object_id == 0)
   {
-      g_free (handle);
+      // note: tdf#161073 handle is expected to be freed by g_dbus_connection_register_object on failure
       return 0;
   }
 
