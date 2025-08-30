$NetBSD: patch-src20_gkrellsun.c,v 1.3 2025/08/30 08:48:46 pho Exp $

* Avoid "sun" conflict.

* Fix a build breakage with glib2-2.76. No idea why it has a declaration
  here. It conflicts with a macro in <glib-2.0/glib/gstring.h>.

* Uncomment a mysteriously commented line setting textOptions.fontDesc to
  NULL in cb_plugin_disabled(). NULL-ifying it is very important, otherwise
  gkrellsun will crash for use-after-free of PangoFontDescription* when the
  plugin is enabled, disabled, then enabled again.

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
@@ -1160,7 +1163,7 @@ cb_plugin_disabled()
    }
    colorsCreated = FALSE;
    colormap = NULL;
-/*   textOptions.fontDesc = NULL;*/
+   textOptions.fontDesc = NULL;
 }
 
 /* Calculate height and width of text given a Pango Font */
