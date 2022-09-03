$NetBSD: patch-client_gtk3_ibusimcontext.c,v 1.4 2022/09/03 14:14:41 tsutsui Exp $

NetBSD 6.99.25's gcc says:
   error: #pragma GCC diagnostic not allowed inside functions

--- client/gtk3/ibusimcontext.c.orig	2022-08-22 15:32:16.000000000 +0000
+++ client/gtk3/ibusimcontext.c
@@ -801,6 +801,9 @@ daemon_name_vanished (GDBusConnection *c
     _daemon_is_running = FALSE;
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
+
 static void
 ibus_im_context_class_init (IBusIMContextClass *class)
 {
@@ -921,10 +924,7 @@ ibus_im_context_class_init (IBusIMContex
 #if !GTK_CHECK_VERSION (3, 98, 4)
     /* always install snooper */
     if (_key_snooper_id == 0) {
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
         _key_snooper_id = gtk_key_snooper_install (_key_snooper_cb, NULL);
-#pragma GCC diagnostic pop
     }
 #endif
 
@@ -936,23 +936,24 @@ ibus_im_context_class_init (IBusIMContex
                                               NULL,
                                               NULL);
 }
+#pragma GCC diagnostic pop
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 static void
 ibus_im_context_class_fini (IBusIMContextClass *class)
 {
 #if !GTK_CHECK_VERSION (3, 98, 4)
     if (_key_snooper_id != 0) {
         IDEBUG ("snooper is terminated.");
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
         gtk_key_snooper_remove (_key_snooper_id);
-#pragma GCC diagnostic pop
         _key_snooper_id = 0;
     }
 #endif
 
     g_bus_unwatch_name (_daemon_name_watch_id);
 }
+#pragma GCC diagnostic pop
 
 static void
 ibus_im_context_init (GObject *obj)
