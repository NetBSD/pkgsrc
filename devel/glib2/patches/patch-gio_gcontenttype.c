$NetBSD: patch-gio_gcontenttype.c,v 1.1 2013/04/25 12:10:48 joerg Exp $

--- gio/gcontenttype.c.orig	2013-04-23 20:39:41.000000000 +0000
+++ gio/gcontenttype.c
@@ -393,6 +393,8 @@ g_content_type_get_mime_type (const char
   return g_strdup (type);
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 
 static GIcon *
 g_content_type_get_icon_internal (const gchar *type,
@@ -457,6 +459,7 @@ g_content_type_get_icon_internal (const 
 
   return themed_icon;
 }
+#pragma GCC diagnostic pop
 
 /**
  * g_content_type_get_icon:
