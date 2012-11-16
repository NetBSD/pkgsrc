$NetBSD: patch-src_ui_dialog_inkscape-preferences.cpp,v 1.1 2012/11/16 00:54:05 joerg Exp $

--- src/ui/dialog/inkscape-preferences.cpp.orig	2012-11-15 16:58:17.000000000 +0000
+++ src/ui/dialog/inkscape-preferences.cpp
@@ -1236,7 +1236,7 @@ void InkscapePreferences::initPageBitmap
         gchar** splits = g_strsplit(choices.data(), ",", 0);
         gint numIems = g_strv_length(splits);
 
-        Glib::ustring labels[numIems];
+        Glib::ustring *labels = new Glib::ustring[numIems];
         int values[numIems];
         for ( gint i = 0; i < numIems; i++) {
             values[i] = i;
@@ -1246,6 +1246,7 @@ void InkscapePreferences::initPageBitmap
         _page_bitmaps.add_line( false, _("Bitmap editor:"), _misc_bitmap_editor, "", "", false);
 
         g_strfreev(splits);
+        delete[] labels;
     }
 
     _bitmap_copy_res.init("/options/createbitmap/resolution", 1.0, 6000.0, 1.0, 1.0, PX_PER_IN, true, false);
