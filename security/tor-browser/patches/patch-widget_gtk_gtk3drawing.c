$NetBSD: patch-widget_gtk_gtk3drawing.c,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- widget/gtk/gtk3drawing.c.orig	2015-05-04 00:43:35.000000000 +0000
+++ widget/gtk/gtk3drawing.c
@@ -65,6 +65,7 @@ static GtkWidget* gScrolledWindowWidget;
 static style_prop_t style_prop_func;
 static gboolean have_arrow_scaling;
 static gboolean checkbox_check_state;
+static gboolean notebook_has_tab_gap;
 static gboolean is_initialized;
 
 #define ARROW_UP      0
@@ -725,6 +726,14 @@ moz_gtk_init()
     else
         checkbox_check_state = GTK_STATE_FLAG_ACTIVE;
 
+    if(!gtk_check_version(3, 12, 0)) {
+        ensure_tab_widget();
+        gtk_widget_style_get(gTabWidget, "has-tab-gap", &notebook_has_tab_gap, NULL);
+    }
+    else {
+        notebook_has_tab_gap = TRUE;
+    }
+
     /* Add style property to GtkEntry.
      * Adding the style property to the normal GtkEntry class means that it
      * will work without issues inside GtkComboBox and for Spinbuttons. */
@@ -762,37 +771,17 @@ moz_gtk_radio_get_metrics(gint* indicato
 gint
 moz_gtk_get_focus_outline_size(gint* focus_h_width, gint* focus_v_width)
 {
-    gboolean interior_focus;
-    gint focus_width = 0;
+    GtkBorder border;
+    GtkBorder padding;
+    GtkStyleContext *style;
 
     ensure_entry_widget();
-    gtk_widget_style_get(gEntryWidget,
-                         "interior-focus", &interior_focus,
-                         "focus-line-width", &focus_width,
-                         NULL);
-    if (interior_focus) {
-        GtkBorder border;
-        GtkStyleContext *style = gtk_widget_get_style_context(gEntryWidget);
-        gtk_style_context_get_border(style, 0, &border);
-        *focus_h_width = border.left + focus_width;
-        *focus_v_width = border.top + focus_width;
-    } else {
-        *focus_h_width = focus_width;
-        *focus_v_width = focus_width;
-    }
-    return MOZ_GTK_SUCCESS;
-}
-
-gint
-moz_gtk_widget_get_focus(GtkWidget* widget, gboolean* interior_focus,
-                         gint* focus_width, gint* focus_pad) 
-{
-    gtk_widget_style_get (widget,
-                          "interior-focus", interior_focus,
-                          "focus-line-width", focus_width,
-                          "focus-padding", focus_pad,
-                          NULL);
+    style = gtk_widget_get_style_context(gEntryWidget);
 
+    gtk_style_context_get_border(style, 0, &border);
+    gtk_style_context_get_padding(style, 0, &padding);
+    *focus_h_width = border.left + padding.left;
+    *focus_v_width = border.top + padding.top;
     return MOZ_GTK_SUCCESS;
 }
 
@@ -880,24 +869,6 @@ moz_gtk_splitter_get_metrics(gint orient
     return MOZ_GTK_SUCCESS;
 }
 
-gint
-moz_gtk_button_get_inner_border(GtkWidget* widget, GtkBorder* inner_border)
-{
-    static const GtkBorder default_inner_border = { 1, 1, 1, 1 };
-    GtkBorder *tmp_border;
-
-    gtk_widget_style_get (widget, "inner-border", &tmp_border, NULL);
-
-    if (tmp_border) {
-        *inner_border = *tmp_border;
-        gtk_border_free(tmp_border);
-    }
-    else
-        *inner_border = default_inner_border;
-
-    return MOZ_GTK_SUCCESS;
-}
-
 static gint
 moz_gtk_button_paint(cairo_t *cr, GdkRectangle* rect,
                      GtkWidgetState* state,
@@ -908,19 +879,8 @@ moz_gtk_button_paint(cairo_t *cr, GdkRec
     GtkStyleContext* style = gtk_widget_get_style_context(widget);    
     gint x = rect->x, y=rect->y, width=rect->width, height=rect->height;
 
-    gboolean interior_focus;
-    gint focus_width, focus_pad;
-
-    moz_gtk_widget_get_focus(widget, &interior_focus, &focus_width, &focus_pad);
     gtk_widget_set_direction(widget, direction);
-
-    if (!interior_focus && state->focused) {
-        x += focus_width + focus_pad;
-        y += focus_width + focus_pad;
-        width -= 2 * (focus_width + focus_pad);
-        height -= 2 * (focus_width + focus_pad);
-    }
-  
+ 
     gtk_style_context_save(style);
     gtk_style_context_set_state(style, state_flags);
 
@@ -953,20 +913,12 @@ moz_gtk_button_paint(cairo_t *cr, GdkRec
     }
 
     if (state->focused) {
-        if (interior_focus) {
-            GtkBorder border;
-            gtk_style_context_get_border(style, state_flags, &border);
-            x += border.left + focus_pad;
-            y += border.top + focus_pad;
-            width -= 2 * (border.left + focus_pad);
-            height -= 2 * (border.top + focus_pad);
-        } else {
-            x -= focus_width + focus_pad;
-            y -= focus_width + focus_pad;
-            width += 2 * (focus_width + focus_pad);
-            height += 2 * (focus_width + focus_pad);
-        }
-
+        GtkBorder border;
+        gtk_style_context_get_border(style, state_flags, &border);
+        x += border.left;
+        y += border.top;
+        width -= (border.left + border.right);
+        height -= (border.top + border.bottom);
         gtk_render_focus(style, cr, x, y, width, height);
     }
     gtk_style_context_restore(style);
@@ -1056,33 +1008,23 @@ calculate_button_inner_rect(GtkWidget* b
                             GtkTextDirection direction,
                             gboolean ignore_focus)
 {
-    GtkBorder inner_border;
-    gboolean interior_focus;
-    gint focus_width, focus_pad;
     GtkStyleContext* style;
     GtkBorder border;
+    GtkBorder padding = {0, 0, 0, 0};
 
     style = gtk_widget_get_style_context(button);
 
     /* This mirrors gtkbutton's child positioning */
-    moz_gtk_button_get_inner_border(button, &inner_border);
-    moz_gtk_widget_get_focus(button, &interior_focus,
-                             &focus_width, &focus_pad);
-
-    if (ignore_focus)
-        focus_width = focus_pad = 0;
-
     gtk_style_context_get_border(style, 0, &border);
+    if (!ignore_focus)
+        gtk_style_context_get_padding(style, 0, &padding);
 
-    inner_rect->x = rect->x + border.left + focus_width + focus_pad;
-    inner_rect->x += direction == GTK_TEXT_DIR_LTR ?
-                        inner_border.left : inner_border.right;
-    inner_rect->y = rect->y + inner_border.top + border.top +
-                    focus_width + focus_pad;
-    inner_rect->width = MAX(1, rect->width - inner_border.left -
-       inner_border.right - (border.left + focus_pad + focus_width) * 2);
-    inner_rect->height = MAX(1, rect->height - inner_border.top -
-       inner_border.bottom - (border.top + focus_pad + focus_width) * 2);
+    inner_rect->x = rect->x + border.left + padding.left;
+    inner_rect->y = rect->y + padding.top + border.top;
+    inner_rect->width = MAX(1, rect->width - padding.left -
+       padding.right - border.left * 2);
+    inner_rect->height = MAX(1, rect->height - padding.top -
+       padding.bottom - border.top * 2);
 
     return MOZ_GTK_SUCCESS;
 }
@@ -1230,6 +1172,7 @@ moz_gtk_scrollbar_thumb_paint(GtkThemeWi
     GtkStyleContext* style;
     GtkScrollbar *scrollbar;
     GtkAdjustment *adj;
+    GtkBorder margin;
 
     ensure_scrollbar_widget();
 
@@ -1239,15 +1182,20 @@ moz_gtk_scrollbar_thumb_paint(GtkThemeWi
         scrollbar = GTK_SCROLLBAR(gVertScrollbarWidget);
 
     gtk_widget_set_direction(GTK_WIDGET(scrollbar), direction);
-  
+
     style = gtk_widget_get_style_context(GTK_WIDGET(scrollbar));
     gtk_style_context_save(style);
-       
+
     gtk_style_context_add_class(style, GTK_STYLE_CLASS_SLIDER);
     gtk_style_context_set_state(style, state_flags);
 
-    gtk_render_slider(style, cr, rect->x, rect->y,
-                      rect->width,  rect->height,
+    gtk_style_context_get_margin (style, state_flags, &margin);
+
+    gtk_render_slider(style, cr,
+                      rect->x + margin.left,
+                      rect->y + margin.top,
+                      rect->width - margin.left - margin.right,
+                      rect->height - margin.top - margin.bottom,
                      (widget == MOZ_GTK_SCROLLBAR_THUMB_HORIZONTAL) ?
                      GTK_ORIENTATION_HORIZONTAL : GTK_ORIENTATION_VERTICAL);
 
@@ -1451,19 +1399,12 @@ moz_gtk_entry_paint(cairo_t *cr, GdkRect
 {
     gint x = rect->x, y = rect->y, width = rect->width, height = rect->height;
     GtkStyleContext* style;
-    gboolean interior_focus;
-    gint focus_width;
     int draw_focus_outline_only = state->depressed; // NS_THEME_FOCUS_OUTLINE
 
     gtk_widget_set_direction(widget, direction);
 
     style = gtk_widget_get_style_context(widget);
 
-    gtk_widget_style_get(widget,
-                         "interior-focus", &interior_focus,
-                         "focus-line-width", &focus_width,
-                         NULL);
-
     if (draw_focus_outline_only) {
         // Inflate the given 'rect' with the focus outline size.
         gint h, v;
@@ -1495,14 +1436,6 @@ moz_gtk_entry_paint(cairo_t *cr, GdkRect
         /* This will get us the lit borders that focused textboxes enjoy on
          * some themes. */
         gtk_style_context_set_state(style, GTK_STATE_FLAG_FOCUSED);
-        if (!interior_focus) {
-            /* Indent the border a little bit if we have exterior focus 
-               (this is what GTK does to draw native entries) */
-            x += focus_width;
-            y += focus_width;
-            width -= 2 * focus_width;
-            height -= 2 * focus_width;
-        }
     }
 
     if (state->disabled) {
@@ -1514,11 +1447,6 @@ moz_gtk_entry_paint(cairo_t *cr, GdkRect
     }
     gtk_render_frame(style, cr, x, y, width, height);
 
-    if (state->focused && !state->disabled) {
-        if (!interior_focus) {
-            gtk_render_focus(style, cr, rect->x, rect->y, rect->width, rect->height);
-        }
-    }
     gtk_style_context_restore(style);
 
     return MOZ_GTK_SUCCESS;
@@ -1823,8 +1751,6 @@ moz_gtk_container_paint(cairo_t *cr, Gdk
     GtkStateFlags state_flags = GetStateFlagsFromGtkWidgetState(state);
     GtkStyleContext* style;
     GtkWidget *widget;
-    gboolean interior_focus;
-    gint focus_width, focus_pad;
 
     if (isradio) {
         ensure_radiobutton_widget();
@@ -1837,7 +1763,6 @@ moz_gtk_container_paint(cairo_t *cr, Gdk
 
     style = gtk_widget_get_style_context(widget);
     gtk_style_context_save(style);
-    moz_gtk_widget_get_focus(widget, &interior_focus, &focus_width, &focus_pad);
     gtk_style_context_set_state(style, state_flags);
   
     /* this is for drawing a prelight box */
@@ -1846,10 +1771,6 @@ moz_gtk_container_paint(cairo_t *cr, Gdk
                               rect->x, rect->y, rect->width, rect->height);
     }
   
-    if (state->focused && !interior_focus) {
-        gtk_render_focus(style, cr,
-                        rect->x, rect->y, rect->width, rect->height);
-    }
     gtk_style_context_restore(style);
   
     return MOZ_GTK_SUCCESS;
@@ -1862,7 +1783,6 @@ moz_gtk_toggle_label_paint(cairo_t *cr, 
 {
     GtkStyleContext *style;
     GtkWidget *widget;
-    gboolean interior_focus;
 
     if (!state->focused)
         return MOZ_GTK_SUCCESS;
@@ -1883,10 +1803,6 @@ moz_gtk_toggle_label_paint(cairo_t *cr, 
     }
     gtk_widget_set_direction(widget, direction);
 
-    gtk_widget_style_get(widget, "interior-focus", &interior_focus, NULL);
-    if (!interior_focus)
-        return MOZ_GTK_SUCCESS;
-
     gtk_style_context_set_state(style, GetStateFlagsFromGtkWidgetState(state));
     gtk_render_focus(style, cr,
                     rect->x, rect->y, rect->width, rect->height);
@@ -2105,6 +2021,9 @@ moz_gtk_get_tab_thickness(void)
     GtkStyleContext * style;
 
     ensure_tab_widget();
+    if (!notebook_has_tab_gap)
+      return 0; /* tabs do not overdraw the tabpanel border with "no gap" style */
+
     style = gtk_widget_get_style_context(gTabWidget);
     gtk_style_context_add_class(style, GTK_STYLE_CLASS_NOTEBOOK);
     gtk_style_context_get_border(style, 0, &border);
@@ -2150,7 +2069,7 @@ moz_gtk_tab_paint(cairo_t *cr, GdkRectan
     ensure_tab_widget();
     gtk_widget_set_direction(gTabWidget, direction);
 
-    style = gtk_widget_get_style_context(gTabWidget);    
+    style = gtk_widget_get_style_context(gTabWidget);
     gtk_style_context_save(style);
     moz_gtk_tab_prepare_style_context(style, flags);
 
@@ -2167,143 +2086,155 @@ moz_gtk_tab_paint(cairo_t *cr, GdkRectan
 
     focusRect = backRect = tabRect;
 
-    if ((flags & MOZ_GTK_TAB_SELECTED) == 0) {
-        /* Only draw the tab */
-        gtk_render_extension(style, cr,
-                             tabRect.x, tabRect.y, tabRect.width, tabRect.height,
-                            (flags & MOZ_GTK_TAB_BOTTOM) ?
-                                GTK_POS_TOP : GTK_POS_BOTTOM );
-    } else {
-        /* Draw the tab and the gap
-         * We want the gap to be positioned exactly on the tabpanel top
-         * border; since tabbox.css may set a negative margin so that the tab
-         * frame rect already overlaps the tabpanel frame rect, we need to take
-         * that into account when drawing. To that effect, nsNativeThemeGTK
-         * passes us this negative margin (bmargin in the graphic below) in the
-         * lowest bits of |flags|.  We use it to set gap_voffset, the distance
-         * between the top of the gap and the bottom of the tab (resp. the
-         * bottom of the gap and the top of the tab when we draw a bottom tab),
-         * while ensuring that the gap always touches the border of the tab,
-         * i.e. 0 <= gap_voffset <= gap_height, to avoid surprinsing results
-         * with big negative or positive margins.
-         * Here is a graphical explanation in the case of top tabs:
-         *             ___________________________
-         *            /                           \
-         *           |            T A B            |
-         * ----------|. . . . . . . . . . . . . . .|----- top of tabpanel
-         *           :    ^       bmargin          :  ^
-         *           :    | (-negative margin,     :  |
-         *  bottom   :    v  passed in flags)      :  |       gap_height
-         *    of  -> :.............................:  |    (the size of the
-         * the tab   .       part of the gap       .  |  tabpanel top border)
-         *           .      outside of the tab     .  v
-         * ----------------------------------------------
-         *
-         * To draw the gap, we use gtk_paint_box_gap(), see comment in
-         * moz_gtk_tabpanels_paint(). This box_gap is made 3 * gap_height tall,
-         * which should suffice to ensure that the only visible border is the
-         * pierced one.  If the tab is in the middle, we make the box_gap begin
-         * a bit to the left of the tab and end a bit to the right, adjusting
-         * the gap position so it still is under the tab, because we want the
-         * rendering of a gap in the middle of a tabpanel.  This is the role of
-         * the gints gap_{l,r}_offset. On the contrary, if the tab is the
-         * first, we align the start border of the box_gap with the start
-         * border of the tab (left if LTR, right if RTL), by setting the
-         * appropriate offset to 0.*/
-        gint gap_loffset, gap_roffset, gap_voffset, gap_height;
-
-        /* Get height needed by the gap */
-        gap_height = moz_gtk_get_tab_thickness();
-
-        /* Extract gap_voffset from the first bits of flags */
-        gap_voffset = flags & MOZ_GTK_TAB_MARGIN_MASK;
-        if (gap_voffset > gap_height)
-            gap_voffset = gap_height;
-
-        /* Set gap_{l,r}_offset to appropriate values */
-        gap_loffset = gap_roffset = 20; /* should be enough */
-        if (flags & MOZ_GTK_TAB_FIRST) {
-            if (direction == GTK_TEXT_DIR_RTL)
-                gap_roffset = initial_gap;
-            else
-                gap_loffset = initial_gap;
-        }
-
-        if (flags & MOZ_GTK_TAB_BOTTOM) {
-            /* Draw the tab on bottom */
-            focusRect.y += gap_voffset;
-            focusRect.height -= gap_voffset;
-
+    if (notebook_has_tab_gap) {
+        if ((flags & MOZ_GTK_TAB_SELECTED) == 0) {
+            /* Only draw the tab */
             gtk_render_extension(style, cr,
-                                 tabRect.x, tabRect.y + gap_voffset, tabRect.width,
-                                 tabRect.height - gap_voffset, GTK_POS_TOP);
-
-            gtk_style_context_remove_region(style, GTK_STYLE_REGION_TAB);
-
-            backRect.y += (gap_voffset - gap_height);
-            backRect.height = gap_height;
-
-            /* Draw the gap; erase with background color before painting in
-             * case theme does not */
-            gtk_render_background(style, cr, backRect.x, backRect.y,
-                                 backRect.width, backRect.height);
-            cairo_save(cr);
-            cairo_rectangle(cr, backRect.x, backRect.y, backRect.width, backRect.height);
-            cairo_clip(cr);
-
-            gtk_render_frame_gap(style, cr,
-                                 tabRect.x - gap_loffset,
-                                 tabRect.y + gap_voffset - 3 * gap_height,
-                                 tabRect.width + gap_loffset + gap_roffset,
-                                 3 * gap_height, GTK_POS_BOTTOM,
-                                 gap_loffset, gap_loffset + tabRect.width);
-            cairo_restore(cr);
+                                 tabRect.x, tabRect.y, tabRect.width, tabRect.height,
+                                (flags & MOZ_GTK_TAB_BOTTOM) ?
+                                    GTK_POS_TOP : GTK_POS_BOTTOM );
         } else {
-            /* Draw the tab on top */
-            focusRect.height -= gap_voffset;
-            gtk_render_extension(style, cr,
-                                 tabRect.x, tabRect.y, tabRect.width,
-                                 tabRect.height - gap_voffset, GTK_POS_BOTTOM);
-
-            gtk_style_context_remove_region(style, GTK_STYLE_REGION_TAB);
-
-            backRect.y += (tabRect.height - gap_voffset);
-            backRect.height = gap_height;
+            /* Draw the tab and the gap
+             * We want the gap to be positioned exactly on the tabpanel top
+             * border; since tabbox.css may set a negative margin so that the tab
+             * frame rect already overlaps the tabpanel frame rect, we need to take
+             * that into account when drawing. To that effect, nsNativeThemeGTK
+             * passes us this negative margin (bmargin in the graphic below) in the
+             * lowest bits of |flags|.  We use it to set gap_voffset, the distance
+             * between the top of the gap and the bottom of the tab (resp. the
+             * bottom of the gap and the top of the tab when we draw a bottom tab),
+             * while ensuring that the gap always touches the border of the tab,
+             * i.e. 0 <= gap_voffset <= gap_height, to avoid surprinsing results
+             * with big negative or positive margins.
+             * Here is a graphical explanation in the case of top tabs:
+             *             ___________________________
+             *            /                           \
+             *           |            T A B            |
+             * ----------|. . . . . . . . . . . . . . .|----- top of tabpanel
+             *           :    ^       bmargin          :  ^
+             *           :    | (-negative margin,     :  |
+             *  bottom   :    v  passed in flags)      :  |       gap_height
+             *    of  -> :.............................:  |    (the size of the
+             * the tab   .       part of the gap       .  |  tabpanel top border)
+             *           .      outside of the tab     .  v
+             * ----------------------------------------------
+             *
+             * To draw the gap, we use gtk_paint_box_gap(), see comment in
+             * moz_gtk_tabpanels_paint(). This box_gap is made 3 * gap_height tall,
+             * which should suffice to ensure that the only visible border is the
+             * pierced one.  If the tab is in the middle, we make the box_gap begin
+             * a bit to the left of the tab and end a bit to the right, adjusting
+             * the gap position so it still is under the tab, because we want the
+             * rendering of a gap in the middle of a tabpanel.  This is the role of
+             * the gints gap_{l,r}_offset. On the contrary, if the tab is the
+             * first, we align the start border of the box_gap with the start
+             * border of the tab (left if LTR, right if RTL), by setting the
+             * appropriate offset to 0.*/
+            gint gap_loffset, gap_roffset, gap_voffset, gap_height;
+
+            /* Get height needed by the gap */
+            gap_height = moz_gtk_get_tab_thickness();
+
+            /* Extract gap_voffset from the first bits of flags */
+            gap_voffset = flags & MOZ_GTK_TAB_MARGIN_MASK;
+            if (gap_voffset > gap_height)
+                gap_voffset = gap_height;
+
+            /* Set gap_{l,r}_offset to appropriate values */
+            gap_loffset = gap_roffset = 20; /* should be enough */
+            if (flags & MOZ_GTK_TAB_FIRST) {
+                if (direction == GTK_TEXT_DIR_RTL)
+                    gap_roffset = initial_gap;
+                else
+                    gap_loffset = initial_gap;
+            }
 
-            /* Draw the gap; erase with background color before painting in
-             * case theme does not */
-            gtk_render_background(style, cr, backRect.x, backRect.y,
-                                  backRect.width, backRect.height);
-
-            cairo_save(cr);
-            cairo_rectangle(cr, backRect.x, backRect.y, backRect.width, backRect.height);
-            cairo_clip(cr);
-
-            gtk_render_frame_gap(style, cr,
-                                 tabRect.x - gap_loffset,
-                                 tabRect.y + tabRect.height - gap_voffset,
-                                 tabRect.width + gap_loffset + gap_roffset,
-                                 3 * gap_height, GTK_POS_TOP,
-                                 gap_loffset, gap_loffset + tabRect.width);
-            cairo_restore(cr);
+            if (flags & MOZ_GTK_TAB_BOTTOM) {
+                /* Draw the tab on bottom */
+                focusRect.y += gap_voffset;
+                focusRect.height -= gap_voffset;
+
+                gtk_render_extension(style, cr,
+                                     tabRect.x, tabRect.y + gap_voffset, tabRect.width,
+                                     tabRect.height - gap_voffset, GTK_POS_TOP);
+
+                gtk_style_context_remove_region(style, GTK_STYLE_REGION_TAB);
+
+                backRect.y += (gap_voffset - gap_height);
+                backRect.height = gap_height;
+
+                /* Draw the gap; erase with background color before painting in
+                 * case theme does not */
+                gtk_render_background(style, cr, backRect.x, backRect.y,
+                                     backRect.width, backRect.height);
+                cairo_save(cr);
+                cairo_rectangle(cr, backRect.x, backRect.y, backRect.width, backRect.height);
+                cairo_clip(cr);
+
+                gtk_render_frame_gap(style, cr,
+                                     tabRect.x - gap_loffset,
+                                     tabRect.y + gap_voffset - 3 * gap_height,
+                                     tabRect.width + gap_loffset + gap_roffset,
+                                     3 * gap_height, GTK_POS_BOTTOM,
+                                     gap_loffset, gap_loffset + tabRect.width);
+                cairo_restore(cr);
+            } else {
+                /* Draw the tab on top */
+                focusRect.height -= gap_voffset;
+                gtk_render_extension(style, cr,
+                                     tabRect.x, tabRect.y, tabRect.width,
+                                     tabRect.height - gap_voffset, GTK_POS_BOTTOM);
+
+                gtk_style_context_remove_region(style, GTK_STYLE_REGION_TAB);
+
+                backRect.y += (tabRect.height - gap_voffset);
+                backRect.height = gap_height;
+
+                /* Draw the gap; erase with background color before painting in
+                 * case theme does not */
+                gtk_render_background(style, cr, backRect.x, backRect.y,
+                                      backRect.width, backRect.height);
+
+                cairo_save(cr);
+                cairo_rectangle(cr, backRect.x, backRect.y, backRect.width, backRect.height);
+                cairo_clip(cr);
+
+                gtk_render_frame_gap(style, cr,
+                                     tabRect.x - gap_loffset,
+                                     tabRect.y + tabRect.height - gap_voffset,
+                                     tabRect.width + gap_loffset + gap_roffset,
+                                     3 * gap_height, GTK_POS_TOP,
+                                     gap_loffset, gap_loffset + tabRect.width);
+                cairo_restore(cr);
+            }
         }
+    } else {
+        gtk_render_background(style, cr, tabRect.x, tabRect.y, tabRect.width, tabRect.height);
+        gtk_render_frame(style, cr, tabRect.x, tabRect.y, tabRect.width, tabRect.height);
     }
 
+    gtk_style_context_restore(style);
+
     if (state->focused) {
       /* Paint the focus ring */
-      GtkBorder border;
-      gtk_style_context_get_border(style, GetStateFlagsFromGtkWidgetState(state), &border);
+      GtkBorder padding;
+
+      gtk_style_context_save(style);
+      moz_gtk_tab_prepare_style_context(style, flags);
 
-      focusRect.x += border.left;
-      focusRect.width -= (border.left + border.right);
-      focusRect.y += border.top;
-      focusRect.height -= (border.top + border.bottom);
+      gtk_style_context_get_padding(style, GetStateFlagsFromGtkWidgetState(state), &padding);
+
+      focusRect.x += padding.left;
+      focusRect.width -= (padding.left + padding.right);
+      focusRect.y += padding.top;
+      focusRect.height -= (padding.top + padding.bottom);
 
       gtk_render_focus(style, cr,
                       focusRect.x, focusRect.y, focusRect.width, focusRect.height);
+
+      gtk_style_context_restore(style);
     }
 
-    gtk_style_context_restore(style);
 
     return MOZ_GTK_SUCCESS;
 }
@@ -2684,26 +2615,18 @@ moz_gtk_get_widget_border(GtkThemeWidget
     switch (widget) {
     case MOZ_GTK_BUTTON:
         {
-            GtkBorder inner_border;
-            gboolean interior_focus;
-            gint focus_width, focus_pad;
-
             ensure_button_widget();
+            style = gtk_widget_get_style_context(gButtonWidget);
+
             *left = *top = *right = *bottom = gtk_container_get_border_width(GTK_CONTAINER(gButtonWidget));
 
             /* Don't add this padding in HTML, otherwise the buttons will
                become too big and stuff the layout. */
             if (!inhtml) {
-                moz_gtk_widget_get_focus(gButtonWidget, &interior_focus, &focus_width, &focus_pad);
-                moz_gtk_button_get_inner_border(gButtonWidget, &inner_border);
-                *left += focus_width + focus_pad + inner_border.left;
-                *right += focus_width + focus_pad + inner_border.right;
-                *top += focus_width + focus_pad + inner_border.top;
-                *bottom += focus_width + focus_pad + inner_border.bottom;
+                moz_gtk_add_style_padding(style, left, top, right, bottom);
             }
 
-            moz_gtk_add_style_border(gtk_widget_get_style_context(gButtonWidget), 
-                                     left, top, right, bottom);
+            moz_gtk_add_style_border(style, left, top, right, bottom);
             return MOZ_GTK_SUCCESS;
         }
     case MOZ_GTK_ENTRY:
@@ -2711,7 +2634,13 @@ moz_gtk_get_widget_border(GtkThemeWidget
             ensure_entry_widget();
             style = gtk_widget_get_style_context(gEntryWidget);
             moz_gtk_add_style_border(style, left, top, right, bottom);
-            moz_gtk_add_style_padding(style, left, top, right, bottom);
+
+            /* Use the document padding in HTML
+               and GTK style padding in XUL. */
+            if (!inhtml) {
+                moz_gtk_add_style_padding(style, left, top, right, bottom);
+            }
+
             return MOZ_GTK_SUCCESS;
         }
     case MOZ_GTK_TREEVIEW:
@@ -2731,23 +2660,15 @@ moz_gtk_get_widget_border(GtkThemeWidget
              * assigned.
              * That is why the following code is the same as for MOZ_GTK_BUTTON.  
              * */
-
-            GtkBorder inner_border;
-            gboolean interior_focus;
-            gint focus_width, focus_pad;
+            GtkStyleContext *style;
 
             ensure_tree_header_cell_widget();
             *left = *top = *right = *bottom = gtk_container_get_border_width(GTK_CONTAINER(gTreeHeaderCellWidget));
 
-            moz_gtk_widget_get_focus(gTreeHeaderCellWidget, &interior_focus, &focus_width, &focus_pad);
-            moz_gtk_button_get_inner_border(gTreeHeaderCellWidget, &inner_border);
-            *left += focus_width + focus_pad + inner_border.left;
-            *right += focus_width + focus_pad + inner_border.right;
-            *top += focus_width + focus_pad + inner_border.top;
-            *bottom += focus_width + focus_pad + inner_border.bottom;
-        
-            moz_gtk_add_style_border(gtk_widget_get_style_context(gTreeHeaderCellWidget), 
-                                     left, top, right, bottom);
+            style = gtk_widget_get_style_context(gTreeHeaderCellWidget);
+
+            moz_gtk_add_style_border(style, left, top, right, bottom);
+            moz_gtk_add_style_padding(style, left, top, right, bottom);
             return MOZ_GTK_SUCCESS;
         }
     case MOZ_GTK_TREE_HEADER_SORTARROW:
@@ -2767,29 +2688,23 @@ moz_gtk_get_widget_border(GtkThemeWidget
             /* We need to account for the arrow on the dropdown, so text
              * doesn't come too close to the arrow, or in some cases spill
              * into the arrow. */
-            gboolean ignored_interior_focus, wide_separators;
-            gint focus_width, focus_pad, separator_width;
+            gboolean wide_separators;
+            gint separator_width;
             GtkRequisition arrow_req;
             GtkBorder border;
 
             ensure_combo_box_widgets();
 
-            *left = gtk_container_get_border_width(GTK_CONTAINER(gComboBoxButtonWidget));
+            *left = *top = *right = *bottom = 
+                gtk_container_get_border_width(GTK_CONTAINER(gComboBoxButtonWidget));
+
+            style = gtk_widget_get_style_context(gComboBoxButtonWidget);
 
             if (!inhtml) {
-                moz_gtk_widget_get_focus(gComboBoxButtonWidget,
-                                         &ignored_interior_focus,
-                                         &focus_width, &focus_pad);
-                *left += focus_width + focus_pad;
+                moz_gtk_add_style_padding(style, left, top, right, bottom);
             }
           
-            style = gtk_widget_get_style_context(gComboBoxButtonWidget);
-            gtk_style_context_get_border(style, 0, &border);
-
-            *top = *left + border.top;
-            *left += border.left;
-
-            *right = *left; *bottom = *top;
+            moz_gtk_add_style_border(style, left, top, right, bottom);
 
             /* If there is no separator, don't try to count its width. */
             separator_width = 0;
@@ -2841,60 +2756,23 @@ moz_gtk_get_widget_border(GtkThemeWidget
         ensure_frame_widget();
         w = gFrameWidget;
         break;
-    case MOZ_GTK_CHECKBUTTON_LABEL:
-    case MOZ_GTK_RADIOBUTTON_LABEL:
-        {
-            gboolean interior_focus;
-            gint focus_width, focus_pad;
-
-            /* If the focus is interior, then the label has a border of
-               (focus_width + focus_pad). */
-            if (widget == MOZ_GTK_CHECKBUTTON_LABEL) {
-                ensure_checkbox_widget();
-                moz_gtk_widget_get_focus(gCheckboxWidget, &interior_focus,
-                                           &focus_width, &focus_pad);
-            }
-            else {
-                ensure_radiobutton_widget();
-                moz_gtk_widget_get_focus(gRadiobuttonWidget, &interior_focus,
-                                        &focus_width, &focus_pad);
-            }
-
-            if (interior_focus)
-                *left = *top = *right = *bottom = (focus_width + focus_pad);
-
-            return MOZ_GTK_SUCCESS;
-        }
-
     case MOZ_GTK_CHECKBUTTON_CONTAINER:
     case MOZ_GTK_RADIOBUTTON_CONTAINER:
         {
-            gboolean interior_focus;
-            gint focus_width, focus_pad;
-
-            /* If the focus is _not_ interior, then the container has a border
-               of (focus_width + focus_pad). */
             if (widget == MOZ_GTK_CHECKBUTTON_CONTAINER) {
                 ensure_checkbox_widget();
-                moz_gtk_widget_get_focus(gCheckboxWidget, &interior_focus,
-                                           &focus_width, &focus_pad);
                 w = gCheckboxWidget;
             } else {
                 ensure_radiobutton_widget();
-                moz_gtk_widget_get_focus(gRadiobuttonWidget, &interior_focus,
-                                        &focus_width, &focus_pad);
                 w = gRadiobuttonWidget;
             }
+            style = gtk_widget_get_style_context(w);
 
             *left = *top = *right = *bottom = gtk_container_get_border_width(GTK_CONTAINER(w));
-
-            if (!interior_focus) {
-                *left += (focus_width + focus_pad);
-                *right += (focus_width + focus_pad);
-                *top += (focus_width + focus_pad);
-                *bottom += (focus_width + focus_pad);
-            }
-
+            moz_gtk_add_style_border(style,
+                                     left, top, right, bottom);
+            moz_gtk_add_style_padding(style,
+                                      left, top, right, bottom);
             return MOZ_GTK_SUCCESS;
         }
     case MOZ_GTK_MENUPOPUP:
@@ -2921,6 +2799,8 @@ moz_gtk_get_widget_border(GtkThemeWidget
             return MOZ_GTK_SUCCESS;
         }
     /* These widgets have no borders, since they are not containers. */
+    case MOZ_GTK_CHECKBUTTON_LABEL:
+    case MOZ_GTK_RADIOBUTTON_LABEL:
     case MOZ_GTK_SPLITTER_HORIZONTAL:
     case MOZ_GTK_SPLITTER_VERTICAL:
     case MOZ_GTK_CHECKBUTTON:
@@ -2975,11 +2855,7 @@ moz_gtk_get_tab_border(gint* left, gint*
     gtk_style_context_save(style);
     moz_gtk_tab_prepare_style_context(style, flags);
 
-    // TODO add_style_border() should be replaced
-    // with focus-line-width and focus-padding
-    // see Bug 877605
     *left = *top = *right = *bottom = 0;
-    moz_gtk_add_style_border(style, left, top, right, bottom);
     moz_gtk_add_style_padding(style, left, top, right, bottom);
 
     gtk_widget_style_get (gTabWidget, "tab-curvature", &tab_curvature, NULL);
@@ -2990,16 +2866,9 @@ moz_gtk_get_tab_border(gint* left, gint*
       int initial_gap;
       gtk_widget_style_get (gTabWidget, "initial-gap", &initial_gap, NULL);
       if (direction == GTK_TEXT_DIR_RTL)
-      	*right += initial_gap;
+        *right += initial_gap;
       else
-      	*left += initial_gap;
-    }
-
-    // Top tabs have no bottom border, bottom tabs have no top border
-    if (flags & MOZ_GTK_TAB_BOTTOM) {
-      *top = 0;
-    } else {
-      *bottom = 0;
+        *left += initial_gap;
     }
 
     gtk_style_context_restore(style);
