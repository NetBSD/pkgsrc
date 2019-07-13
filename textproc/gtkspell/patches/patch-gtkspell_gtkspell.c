$NetBSD: patch-gtkspell_gtkspell.c,v 1.1 2019/07/13 15:41:27 wiz Exp $

Adapt for enchant2.

--- gtkspell/gtkspell.c.orig	2009-10-09 19:01:47.000000000 +0000
+++ gtkspell/gtkspell.c
@@ -277,7 +277,7 @@ add_to_dictionary(GtkWidget *menuitem, G
 	get_word_extents_from_mark(spell->buffer, &start, &end, spell->mark_click);
 	word = gtk_text_buffer_get_text(spell->buffer, &start, &end, FALSE);
 	
-	enchant_dict_add_to_pwl( spell->speller, word, strlen(word));
+	enchant_dict_add( spell->speller, word, strlen(word));
 
 	gtkspell_recheck_all(spell);
 
