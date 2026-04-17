$NetBSD: patch-tog_tog.c,v 1.3 2026/04/17 19:14:28 vins Exp $

The userptr for panels is of type (char*), so add appropriate
type casts.

--- tog/tog.c.orig	2026-04-17 18:18:57.654265899 +0000
+++ tog/tog.c
@@ -928,7 +928,7 @@ view_open(int nlines, int ncols, int beg
 	}
 	view->panel = new_panel(view->window);
 	if (view->panel == NULL ||
-	    set_panel_userptr(view->panel, view) != OK) {
+	    set_panel_userptr(view->panel, (char*)view) != OK) {
 		view_close(view);
 		return NULL;
 	}
@@ -1049,7 +1049,7 @@ view_border(struct tog_view *view)
 	if (panel == NULL)
 		return;
 
-	view_above = panel_userptr(panel);
+	view_above = (const struct tog_view *)panel_userptr(panel);
 	if (view->mode == TOG_VIEW_SPLIT_HRZN)
 		mvwhline(view->window, view_above->begin_y - 1,
 		    view->begin_x, ACS_HLINE, view->ncols);
