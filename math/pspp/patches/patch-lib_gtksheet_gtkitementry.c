$NetBSD: patch-lib_gtksheet_gtkitementry.c,v 1.1 2011/12/20 16:14:44 wiz Exp $

Fix conflict with newer GTK2.

--- lib/gtksheet/gtkitementry.c.orig	2009-09-18 03:05:40.000000000 +0000
+++ lib/gtksheet/gtkitementry.c
@@ -145,7 +145,7 @@ static void         gtk_entry_draw_curso
 static PangoLayout *gtk_entry_ensure_layout            (GtkEntry       *entry,
                                                         gboolean        include_preedit);
 static void         gtk_entry_queue_draw               (GtkEntry       *entry);
-static void         gtk_entry_reset_im_context         (GtkEntry       *entry);
+static void         mygtk_entry_reset_im_context         (GtkEntry       *entry);
 static void         gtk_entry_recompute                (GtkEntry       *entry);
 static void         gtk_entry_get_cursor_locations     (GtkEntry       *entry,
 							CursorType      type,
@@ -694,7 +694,7 @@ gtk_entry_real_set_position (GtkEditable
   if (position != entry->current_pos ||
       position != entry->selection_bound)
     {
-      gtk_entry_reset_im_context (entry);
+      mygtk_entry_reset_im_context (entry);
       gtk_entry_set_positions (entry, position, position);
     }
 }
@@ -895,7 +895,7 @@ gtk_entry_move_cursor (GtkEntry       *e
 {
   gint new_pos = entry->current_pos;
 
-  gtk_entry_reset_im_context (entry);
+  mygtk_entry_reset_im_context (entry);
 
   if (entry->current_pos != entry->selection_bound && !extend_selection)
     {
@@ -989,7 +989,7 @@ gtk_entry_insert_at_cursor (GtkEntry    
 
   if (entry->editable)
     {
-      gtk_entry_reset_im_context (entry);
+      mygtk_entry_reset_im_context (entry);
 
       gtk_editable_insert_text (editable, str, -1, &pos);
       gtk_editable_set_position (editable, pos);
@@ -1005,7 +1005,7 @@ gtk_entry_delete_from_cursor (GtkEntry  
   gint start_pos = entry->current_pos;
   gint end_pos = entry->current_pos;
 
-  gtk_entry_reset_im_context (entry);
+  mygtk_entry_reset_im_context (entry);
 
   if (!entry->editable)
     return;
@@ -1777,7 +1777,7 @@ gtk_entry_queue_draw (GtkEntry *entry)
 }
 
 static void
-gtk_entry_reset_im_context (GtkEntry *entry)
+mygtk_entry_reset_im_context (GtkEntry *entry)
 {
   if (entry->need_im_reset)
     {
