$NetBSD: patch-d__text.c,v 1.1 2012/12/24 21:12:36 joerg Exp $

--- d_text.c.orig	2012-12-23 17:34:56.000000000 +0000
+++ d_text.c
@@ -1880,10 +1880,7 @@ SetGeometry(ic, name, area)
   XFree(list);
 }
 
-xim_set_ic_geometry(ic, width, height)
-     XIC ic;
-     int width;
-     int height;
+void xim_set_ic_geometry(XIC ic, int width, int height)
 {
   XRectangle preedit_area, *preedit_area_ptr;
   XRectangle status_area, *status_area_ptr;
@@ -1951,7 +1948,7 @@ xim_initialize(w)
   else if (strncasecmp(appres.xim_input_style, "None", 3) != 0)
     fprintf(stderr, "xfig: inputStyle should OverTheSpot, OffTheSpot, or Root\n");
 
-  if (preferred_style == style_notuseful) return;
+  if (preferred_style == style_notuseful) return True;
 
   if (appres.DEBUG) fprintf(stderr, "initialize_input_method()...\n");
   if ((modifier_list = XSetLocaleModifiers("")) == NULL || *modifier_list == '\0') {
