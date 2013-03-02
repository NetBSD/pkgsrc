$NetBSD: patch-src_rox__strings.c,v 1.1 2013/03/02 18:13:49 joerg Exp $

--- src/rox_strings.c.orig	2013-03-01 14:28:06.000000000 +0000
+++ src/rox_strings.c
@@ -2222,7 +2222,7 @@ gchar* copied_from_browser_to_ftext (con
 gchar* get_charset_from_meta (const gchar *text)
 {
   if (! text)
-     return;
+     return NULL;
 
   gchar *s1 = strstr (text, "<meta");
   if (! s1)
@@ -2507,7 +2507,7 @@ gchar* str_before_sep (const gchar *str,
 gchar* str_after_sep (const gchar *str, const gchar *sep)
 {
    if ((str == NULL) || (sep == NULL))
-      return;
+      return NULL;
 
    gchar *t = strstr (str, sep);
    if (t)
