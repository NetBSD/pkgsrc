$NetBSD: patch-gtkextra_gtkplot.c,v 1.1 2013/03/02 18:02:11 joerg Exp $

--- gtkextra/gtkplot.c.orig	2013-03-01 16:04:54.000000000 +0000
+++ gtkextra/gtkplot.c
@@ -219,7 +219,7 @@ static void gtk_plot_real_get_point		(Gt
 					 	 gdouble *px, gdouble *py);
 void   gtk_plot_remove_dimension		(GtkPlot *plot, 
 						 const gchar *dimension);
-inline gint roundint				(gdouble x);
+gint roundint				(gdouble x);
 static void update_datasets			(GtkPlot *plot, gboolean new_range);
 
 static GtkWidgetClass *parent_class = NULL;
@@ -2971,7 +2971,7 @@ gtk_plot_ticks_inverse(GtkPlotAxis *axis
     return point;
 }
 
-inline gint
+gint
 roundint (gdouble x)
 {
  return (x+.50999999471);
