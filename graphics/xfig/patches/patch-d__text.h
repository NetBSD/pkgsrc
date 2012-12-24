$NetBSD: patch-d__text.h,v 1.1 2012/12/24 21:12:36 joerg Exp $

--- d_text.h.orig	2012-12-23 17:37:02.000000000 +0000
+++ d_text.h
@@ -36,3 +36,4 @@ extern		kill_preedit();
 #endif  /* I18N_USE_PREEDIT */
 #endif  /* I18N */
 extern void text_drawing_selected (void);
+extern void xim_set_ic_geometry(XIC ic, int width, int height);
