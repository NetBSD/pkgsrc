$NetBSD: patch-utils.c,v 1.1 2013/10/14 14:33:31 joerg Exp $

--- utils.c.orig	2013-10-14 13:14:27.000000000 +0000
+++ utils.c
@@ -899,7 +899,7 @@ void clist_clear(GtkCList *clist)
 
 /* Encapsulate GTK tooltip function which no longer supports disabling as
  * of GTK 2.12 */
-inline void set_tooltip(int show_tooltip, 
+void set_tooltip(int show_tooltip, 
                         GtkTooltips *tooltips,
                         GtkWidget *widget,
                         const gchar *tip_text,
