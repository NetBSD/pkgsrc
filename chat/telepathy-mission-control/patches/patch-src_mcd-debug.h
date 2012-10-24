$NetBSD: patch-src_mcd-debug.h,v 1.1 2012/10/24 15:39:21 joerg Exp $

--- src/mcd-debug.h.orig	2012-10-24 13:23:53.000000000 +0000
+++ src/mcd-debug.h
@@ -35,7 +35,7 @@ G_BEGIN_DECLS
 
 void mcd_debug_init ();
 
-inline gint mcd_debug_get_level ();
+gint mcd_debug_get_level ();
 
 void mcd_debug_ref (gpointer obj, const gchar *filename, gint linenum);
 void mcd_debug_unref (gpointer obj, const gchar *filename, gint linenum);
