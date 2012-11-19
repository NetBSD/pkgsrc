$NetBSD: patch-src_UI__gtk.c,v 1.1 2012/11/19 23:16:41 joerg Exp $

--- src/UI_gtk.c.orig	2012-11-19 16:23:52.000000000 +0000
+++ src/UI_gtk.c
@@ -173,6 +173,11 @@ static void glwidget_realize(GtkWidget *
 	}
 }
 
+static void clicked(GtkButton *button, IBusHandwriteEngine *engine)
+{
+	ibus_handwrite_engine_commit_text(engine,GPOINTER_TO_INT(g_object_get_data(G_OBJECT(button),"order")));
+}
+
 static void regen_loopuptable(GtkWidget * widget, IBusHandwriteEngine * engine)
 {
 	int i;
@@ -195,11 +200,6 @@ static void regen_loopuptable(GtkWidget 
 
 		gtk_widget_show(bt);
 
-		void clicked(GtkButton *button, IBusHandwriteEngine *engine)
-		{
-			ibus_handwrite_engine_commit_text(engine,GPOINTER_TO_INT(g_object_get_data(G_OBJECT(button),"order")));
-		}
-
 		g_object_set_data(G_OBJECT(bt),"order",GINT_TO_POINTER(i));
 		g_signal_connect(bt,"clicked",G_CALLBACK(clicked),engine);
 
