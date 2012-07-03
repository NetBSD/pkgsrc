$NetBSD: patch-src_editor.c,v 1.1 2012/07/03 18:10:51 joerg Exp $

--- src/editor.c.orig	2012-07-03 12:25:51.000000000 +0000
+++ src/editor.c
@@ -404,7 +404,7 @@ extern void		refresh_editor(GtkWidget *E
 /* preconditions:  iter points to possible start of interesting word  
 postconditions: end is set to the end of the word in the buffer if it was found.
 if word found, returns TRUE, else FALSE*/
-inline gboolean starts_string (gchar *text, gint i, gchar *word, gint *end)
+static inline gboolean starts_string (gchar *text, gint i, gchar *word, gint *end)
 {
 	gunichar ch;
 	gunichar k;
@@ -438,7 +438,7 @@ inline gboolean starts_string (gchar *te
 
 
 /* returns color index of match, or -1 if none */
-inline gint is_matching_keyword (gint Lg, const gchar *str)
+static inline gint is_matching_keyword (gint Lg, const gchar *str)
 {
 	gint rv = -1;
 	gpointer val;
@@ -454,7 +454,7 @@ inline gint is_matching_keyword (gint Lg
 }
 
 
-inline void refresh_markers (GtkTextBuffer *Buffer)
+static inline void refresh_markers (GtkTextBuffer *Buffer)
 {
 	gint CurrentPage;
 	gint Lg;
@@ -780,7 +780,7 @@ void search_for_keyword_correctly (gint 
 }
 
 
-inline void search_for_keyword_fastly (gint page, GtkTextBuffer *Buffer, gchar *text, gint *i, gint offset, gint Lg)
+static void search_for_keyword_fastly (gint page, GtkTextBuffer *Buffer, gchar *text, gint *i, gint offset, gint Lg)
 {
 	/* search for a keyword */
 	gint tmp, next;
