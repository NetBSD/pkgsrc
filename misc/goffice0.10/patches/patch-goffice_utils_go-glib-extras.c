$NetBSD: patch-goffice_utils_go-glib-extras.c,v 1.1 2015/08/10 19:30:06 joerg Exp $

Format string is passed in as argument.

--- goffice/utils/go-glib-extras.c.orig	2015-08-10 16:27:43.000000000 +0000
+++ goffice/utils/go-glib-extras.c
@@ -893,6 +893,8 @@ go_object_toggle (gpointer object, const
 	g_object_set (object, property_name, !value, NULL);
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 
 gboolean
 go_object_set_property (GObject *obj, const char *property_name,
@@ -963,8 +965,7 @@ go_object_set_property (GObject *obj, co
 		return TRUE;
 }
 
-
-
+#pragma GCC diagnostic pop
 
 /**
  * go_object_properties_collect:
