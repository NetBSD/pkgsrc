$NetBSD: patch-src_editor.c,v 1.3 2020/04/12 19:49:18 joerg Exp $

--- src/editor.c.orig	2020-04-12 01:01:00.903208293 +0000
+++ src/editor.c
@@ -537,7 +537,7 @@ inline gint is_matching_keyword (gint Lg
 }
 
 
-inline void refresh_markers (GtkTextBuffer * Buffer)
+void refresh_markers (GtkTextBuffer * Buffer)
 {
 	gint CurrentPage;
 	gint Lg;
@@ -894,7 +894,7 @@ void search_for_keyword_correctly (gint 
 END_FCN}
 
 
-inline void search_for_keyword_fastly (gint page, GtkTextBuffer * Buffer,
+void search_for_keyword_fastly (gint page, GtkTextBuffer * Buffer,
 									   gchar * text, gint * i, gint offset,
 									   gint Lg)
 {
