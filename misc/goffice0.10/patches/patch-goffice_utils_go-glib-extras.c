$NetBSD: patch-goffice_utils_go-glib-extras.c,v 1.2 2026/06/09 17:35:16 wiz Exp $

Format string is passed in as argument.

--- goffice/utils/go-glib-extras.c.orig	2026-04-30 00:44:54.000000000 +0000
+++ goffice/utils/go-glib-extras.c
@@ -957,6 +957,8 @@ go_destroy_password (char *passwd)
 	memset (passwd, 0, strlen (passwd));
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 
 /**
  * go_memdup:
@@ -1115,8 +1117,7 @@ go_object_set_property (GObject *obj, const char *prop
 		return TRUE;
 }
 
-
-
+#pragma GCC diagnostic pop
 
 /**
  * go_object_properties_collect:
