$NetBSD: patch-extras_immodules_client-gtk_scim-bridge-client-imcontext-gtk.c,v 1.1 2012/08/19 08:09:08 obache Exp $

--- extras/immodules/client-gtk/scim-bridge-client-imcontext-gtk.c.orig	2012-06-13 15:22:28.000000000 +0000
+++ extras/immodules/client-gtk/scim-bridge-client-imcontext-gtk.c
@@ -684,6 +684,7 @@ void scim_bridge_client_imcontext_regist
 #else
         (GtkObjectInitFunc) scim_bridge_client_imcontext_initialize,
 #endif
+	0
     };
 
     class_type = g_type_module_register_type (type_module, GTK_TYPE_IM_CONTEXT, "ScimBridgeClientIMContext", &klass_info, 0);
