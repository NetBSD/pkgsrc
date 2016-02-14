$NetBSD: patch-widget_gtk_gtkdrawing.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- widget/gtk/gtkdrawing.h.orig	2015-03-27 02:20:33.000000000 +0000
+++ widget/gtk/gtkdrawing.h
@@ -293,16 +293,6 @@ moz_gtk_checkbox_get_metrics(gint* indic
 gint
 moz_gtk_radio_get_metrics(gint* indicator_size, gint* indicator_spacing);
 
-/**
- * Get the inner-border value for a GtkButton widget (button or tree header)
- * widget:             [IN]  the widget to get the border value for 
- * inner_border:       [OUT] the inner border
- *
- * returns:   MOZ_GTK_SUCCESS if there was no error, an error code otherwise
- */
-gint
-moz_gtk_button_get_inner_border(GtkWidget* widget, GtkBorder* inner_border);
-
 /** Get the extra size for the focus ring for outline:auto.
  * widget:             [IN]  the widget to get the focus metrics for    
  * focus_h_width:      [OUT] the horizontal width
@@ -313,19 +303,6 @@ moz_gtk_button_get_inner_border(GtkWidge
 gint
 moz_gtk_get_focus_outline_size(gint* focus_h_width, gint* focus_v_width);
 
-/** Get the focus metrics for a treeheadercell, button, checkbox, or radio button.
- * widget:             [IN]  the widget to get the focus metrics for    
- * interior_focus:     [OUT] whether the focus is drawn around the
- *                           label (TRUE) or around the whole container (FALSE)
- * focus_width:        [OUT] the width of the focus line
- * focus_pad:          [OUT] the padding between the focus line and children
- *
- * returns:    MOZ_GTK_SUCCESS if there was no error, an error code otherwise
- */
-gint
-moz_gtk_widget_get_focus(GtkWidget* widget, gboolean* interior_focus,
-                         gint* focus_width, gint* focus_pad);
-
 /** Get the horizontal padding for the menuitem widget or checkmenuitem widget.
  * horizontal_padding: [OUT] The left and right padding of the menuitem or checkmenuitem
  *
