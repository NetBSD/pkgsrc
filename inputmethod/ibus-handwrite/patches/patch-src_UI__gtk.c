$NetBSD: patch-src_UI__gtk.c,v 1.3 2014/08/28 10:27:28 obache Exp $

* Nested functions are supported as an extension in GNU C.
  http://code.google.com/p/ibus-handwrite/issues/detail?id=20

--- src/UI_gtk.c.orig	2014-08-04 08:24:46.000000000 +0000
+++ src/UI_gtk.c
@@ -74,6 +74,11 @@ static gboolean paint_lines(GtkWidget *w
 	return TRUE;
 }
 
+static void clicked(GtkButton *button, IBusHandwriteEngine *engine)
+{
+	ibus_handwrite_engine_commit_text(engine,GPOINTER_TO_INT(g_object_get_data(G_OBJECT(button),"order")));
+}
+
 static void regen_loopuptable(GtkWidget * widget, IBusHandwriteEngine * engine)
 {
 	int i;
@@ -98,11 +103,6 @@ static void regen_loopuptable(GtkWidget 
 
 		gtk_widget_show(bt);
 
-		void clicked(GtkButton *button, IBusHandwriteEngine *engine)
-		{
-			ibus_handwrite_engine_commit_text(engine,GPOINTER_TO_INT(g_object_get_data(G_OBJECT(button),"order")));
-		}
-
 		g_object_set_data(G_OBJECT(bt),"order",GINT_TO_POINTER(i));
 		g_signal_connect(bt,"clicked",G_CALLBACK(clicked),engine);
 
