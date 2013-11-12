$NetBSD: patch-client_gtk3_ibusimcontext.c,v 1.1 2013/11/12 02:57:43 dholland Exp $

NetBSD 6.99.25's gcc says:
   error: #pragma GCC diagnostic not allowed inside functions

--- client/gtk3/ibusimcontext.c~	2013-09-20 03:15:51.000000000 +0000
+++ client/gtk3/ibusimcontext.c
@@ -509,6 +509,9 @@ daemon_name_vanished (GDBusConnection *c
     _daemon_is_running = FALSE;
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
+
 static void
 ibus_im_context_class_init (IBusIMContextClass *class)
 {
@@ -593,10 +596,7 @@ ibus_im_context_class_init (IBusIMContex
 
     /* always install snooper */
     if (_key_snooper_id == 0) {
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
         _key_snooper_id = gtk_key_snooper_install (_key_snooper_cb, NULL);
-#pragma GCC diagnostic pop
     }
 
     _daemon_name_watch_id = g_bus_watch_name (G_BUS_TYPE_SESSION,
@@ -607,21 +607,22 @@ ibus_im_context_class_init (IBusIMContex
                                               NULL,
                                               NULL);
 }
+#pragma GCC diagnostic pop
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 static void
 ibus_im_context_class_fini (IBusIMContextClass *class)
 {
     if (_key_snooper_id != 0) {
         IDEBUG ("snooper is terminated.");
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
         gtk_key_snooper_remove (_key_snooper_id);
-#pragma GCC diagnostic pop
         _key_snooper_id = 0;
     }
 
     g_bus_unwatch_name (_daemon_name_watch_id);
 }
+#pragma GCC diagnostic pop
 
 /* Copied from gtk+2.0-2.20.1/modules/input/imcedilla.c to fix crosbug.com/11421.
  * Overwrite the original Gtk+'s compose table in gtk+-2.x.y/gtk/gtkimcontextsimple.c. */
