$NetBSD: patch-src_gui-gtk_quarry-text-buffer.c,v 1.1 2012/11/16 00:50:39 joerg Exp $

--- src/gui-gtk/quarry-text-buffer.c.orig	2012-11-15 15:16:11.000000000 +0000
+++ src/gui-gtk/quarry-text-buffer.c
@@ -983,7 +983,7 @@ quarry_text_buffer_undo_entry_delete (Qu
 }
 
 
-inline gboolean
+gboolean
 quarry_text_buffer_undo_entry_is_empty
   (const QuarryTextBufferUndoEntry *undo_entry)
 {
