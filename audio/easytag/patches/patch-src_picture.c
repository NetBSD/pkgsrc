$NetBSD: patch-src_picture.c,v 1.1 2012/12/03 22:39:05 wiz Exp $

Gentoo patch for mp4v2-2.0 compatibility.
https://bugs.gentoo.org/show_bug.cgi?id=409281

--- src/picture.c.orig	2011-07-04 00:59:21.000000000 +0000
+++ src/picture.c
@@ -326,24 +326,7 @@ void Picture_Add_Button_Clicked (GObject
     else if (MESSAGE_BOX_POSITION_MOUSE)
         gtk_window_set_position(GTK_WINDOW(FileSelectionWindow),GTK_WIN_POS_MOUSE);
 
-    // Behaviour following the tag type...
-    switch (ETCore->ETFileDisplayed->ETFileDescription->TagType)
-    {
-        case MP4_TAG:
-        {
-            // Only one file can be selected
-            gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(FileSelectionWindow), FALSE);
-            break;
-        }
-
-        // Other tag types
-        default:
-        {
-            gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(FileSelectionWindow), TRUE);
-            break;
-        }
-    }
-
+    gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(FileSelectionWindow), TRUE);
     gtk_dialog_set_default_response(GTK_DIALOG(FileSelectionWindow), GTK_RESPONSE_OK);
 
     // Starting directory (the same of the current file)
