$NetBSD: patch-src_tea__text__document.c,v 1.1 2013/03/02 18:13:49 joerg Exp $

--- src/tea_text_document.c.orig	2013-03-01 14:27:14.000000000 +0000
+++ src/tea_text_document.c
@@ -2238,7 +2238,7 @@ gchar* doc_get_sel (t_note_page *doc)
 void doc_select_line (t_note_page *doc, gint line)
 {
   if (! doc)
-     return NULL;
+     return;
 
   GtkTextIter itstart, itend;
   gtk_text_buffer_get_iter_at_line (doc->text_buffer, &itstart, line - 1);
@@ -3190,7 +3190,7 @@ void doc_rep_sel (t_note_page *page, con
 gchar* get_c_url (t_note_page *doc)
 {
   if (! doc)
-     return;
+     return NULL;
 
   gchar *dir;
   gchar *filename;
@@ -3282,7 +3282,7 @@ gboolean doc_search_f (t_note_page *doc,
 gboolean doc_search_f_next (t_note_page *doc)
 {
   if (! doc)
-     return;
+     return FALSE;
 
   gboolean result = FALSE;
   if (! doc->last_searched_text)
@@ -4812,18 +4812,18 @@ gboolean text_doc_save_silent (t_note_pa
 t_note_page* doc_is_already_opened (const gchar *filename)
 {
   if (! filename)
-     return;
+     return NULL;
 
   gint i = get_n_page_by_filename (filename);
 
   if (i != -1)
      {
       gtk_notebook_set_current_page (notebook1, i);
-      return;
+      return NULL;
      }
 
   if (! g_file_test (filename, G_FILE_TEST_EXISTS))
-     return;
+     return NULL;
 
   t_note_page *t = open_file_std (filename);
   cur_text_doc = t;
