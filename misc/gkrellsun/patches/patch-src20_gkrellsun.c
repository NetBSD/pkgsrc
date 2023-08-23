$NetBSD: patch-src20_gkrellsun.c,v 1.2 2023/08/23 06:29:53 pho Exp $

* Avoid "sun" conflict.

* Fix a build breakage with glib2-2.76. No idea why it has a declaration
  here. It conflicts with a macro in <glib-2.0/glib/gstring.h>.

--- src20/gkrellsun.c.orig	2006-03-17 13:29:51.000000000 +0000
+++ src20/gkrellsun.c
@@ -16,8 +16,11 @@ time_t* CurrentTime;
 
 #include <math.h>
 
+#ifdef __sun
+#undef sun
+#endif
+
 /* splint */
-extern gchar* g_string_free (/*@only@*/ GString *, gboolean);
 extern void pango_font_description_free (/*@owned@*/PangoFontDescription *);
 
 #define PLUGIN_HEIGHT 54
