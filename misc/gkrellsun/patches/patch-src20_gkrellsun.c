$NetBSD: patch-src20_gkrellsun.c,v 1.1 2022/12/13 13:12:10 jperkin Exp $

Avoid "sun" conflict.

--- src20/gkrellsun.c.orig	2006-03-17 13:29:51.000000000 +0000
+++ src20/gkrellsun.c
@@ -16,6 +16,10 @@ time_t* CurrentTime;
 
 #include <math.h>
 
+#ifdef __sun
+#undef sun
+#endif
+
 /* splint */
 extern gchar* g_string_free (/*@only@*/ GString *, gboolean);
 extern void pango_font_description_free (/*@owned@*/PangoFontDescription *);
