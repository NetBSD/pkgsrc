$NetBSD: patch-panels_power_cc-power-panel.c,v 1.1 2021/06/04 11:27:01 cirnatdan Exp $

Add forgotten #ifdefs for NetworkManager code 

--- panels/power/cc-power-panel.c.orig	2021-03-20 21:52:23.035848900 +0000
+++ panels/power/cc-power-panel.c
@@ -1745,11 +1745,15 @@ cc_power_panel_class_init (CcPowerPanelC
   gtk_widget_class_bind_template_callback (widget_class, has_kbd_brightness_cb);
   gtk_widget_class_bind_template_callback (widget_class, idle_delay_combo_changed_cb);
   gtk_widget_class_bind_template_callback (widget_class, keynav_failed_cb);
+#ifdef HAVE_NETWORK_MANAGER
   gtk_widget_class_bind_template_callback (widget_class, mobile_switch_changed_cb);
+#endif
   gtk_widget_class_bind_template_callback (widget_class, power_button_combo_changed_cb);
   gtk_widget_class_bind_template_callback (widget_class, power_profiles_row_activated_cb);
   gtk_widget_class_bind_template_callback (widget_class, power_saving_listbox_row_activated_cb);
+#ifdef HAVE_NETWORK_MANAGER
   gtk_widget_class_bind_template_callback (widget_class, wifi_switch_changed_cb);
+#endif
 }
 
 static void
