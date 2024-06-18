$NetBSD: patch-tdgtlist.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora 

--- tdgtlist.c.orig	2011-05-16 16:22:00.000000000 +0000
+++ tdgtlist.c
@@ -1052,7 +1052,8 @@ TdgtList *CreateTdgtList(parent_win, par
       v_pad, num_visible_lines, can_select, multicolor, auto_scroll_on_insert)
    Window parent_win;
    TidgetInfo *parent_tidgetinfo;
-   int ctl_id, x, y, w, h_pad, v_pad, num_visible_lines, auto_scroll_on_insert;
+   int ctl_id, x, y, w, h_pad, v_pad, num_visible_lines, can_select,
+   	multicolor, auto_scroll_on_insert;
 {
    int bg_pixel=(threeDLook ? myLtGryPixel : myBgPixel), h=0, content_h=0;
    TdgtList *pTdgtList=NULL;
