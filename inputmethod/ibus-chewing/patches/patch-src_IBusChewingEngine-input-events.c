$NetBSD: patch-src_IBusChewingEngine-input-events.c,v 1.1 2012/04/22 14:09:10 obache Exp $

* for ibus-1.4
  https://github.com/definite/ibus-chewing/pull/16

--- src/IBusChewingEngine-input-events.c.orig	2011-10-12 11:50:51.000000000 +0000
+++ src/IBusChewingEngine-input-events.c
@@ -291,12 +291,20 @@ void ibus_chewing_engine_property_activa
 	/* Toggle Full <-> Half */
 	chewing_set_ShapeMode(self->context, !chewing_get_ShapeMode(self->context));
     }else if (strcmp(prop_name,"chewing_settings_prop")==0){
+#if IBUS_CHECK_VERSION(1, 4, 0)
+	if (ibus_property_get_state(self->settings_prop)==PROP_STATE_UNCHECKED){
+#else
 	if (self->settings_prop->state==PROP_STATE_UNCHECKED){
+#endif
 	    if (gtk_dialog_run(GTK_DIALOG(self->setting_dialog))==GTK_RESPONSE_OK){
 		self_save_config_all(self);
 	    }
 	    gtk_widget_hide(self->setting_dialog);
+#if IBUS_CHECK_VERSION(1, 4, 0)
+	    ibus_property_set_state(self->settings_prop,PROP_STATE_UNCHECKED);
+#else
 	    self->settings_prop->state=PROP_STATE_UNCHECKED;
+#endif
 	}
     }else{
 	G_DEBUG_MSG(3,"[I3]  property_activate(-, %s, %u) not recognized",prop_name, prop_state);
