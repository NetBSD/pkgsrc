$NetBSD: patch-girara_config.c,v 1.1 2016/12/09 08:06:50 leot Exp $

Update font handling for changes in Gtk+ 3.21
(from upstream commit 949c879aa84e9496fabc7d3602060e29f9dc42a1)

--- girara/config.c.orig	2016-04-18 20:35:34.000000000 +0000
+++ girara/config.c
@@ -50,8 +50,7 @@ cb_font(girara_session_t* session, const
 {
   g_return_if_fail(session != NULL && value != NULL);
 
-  girara_template_set_variable_value(session->private_data->csstemplate, "font",
-      value);
+  css_template_fill_font(session->private_data->csstemplate, value);
 }
 
 static void
