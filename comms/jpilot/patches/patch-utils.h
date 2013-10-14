$NetBSD: patch-utils.h,v 1.1 2013/10/14 14:33:31 joerg Exp $

--- utils.h.orig	2013-10-14 13:14:44.000000000 +0000
+++ utils.h
@@ -349,7 +349,7 @@ void entry_set_multiline_truncate(GtkEnt
 
 void clist_clear(GtkCList *clist);
 
-inline void set_tooltip(int show_tooltip, 
+void set_tooltip(int show_tooltip, 
                         GtkTooltips *tooltips,
                         GtkWidget *widget,
                         const gchar *tip_text,
