$NetBSD: patch-thunar_thunar-standard-view.c,v 1.1 2020/01/06 23:29:59 gutteridge Exp $

Fix segfault due to the wrong type being supplied as the sentinel.
https://bugzilla.xfce.org/show_bug.cgi?id=16310

--- thunar/thunar-standard-view.c.orig	2019-11-15 22:31:38.000000000 +0000
+++ thunar/thunar-standard-view.c
@@ -719,7 +719,7 @@ G_GNUC_END_IGNORE_DEPRECATIONS
 #endif
                                                "alignment", PANGO_ALIGN_CENTER,
                                                "xalign", 0.5,
-                                               FALSE);
+                                               NULL);
   g_object_ref_sink (G_OBJECT (standard_view->name_renderer));
 
   /* TODO: prelit underline
