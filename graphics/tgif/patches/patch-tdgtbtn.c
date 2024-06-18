$NetBSD: patch-tdgtbtn.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora 

--- tdgtbtn.c.orig	2011-05-16 16:22:00.000000000 +0000
+++ tdgtbtn.c
@@ -504,7 +504,7 @@ TdgtBtn *CreateTdgtBtn(parent_win, paren
       v_pad, btn_type, btn_style, state, font_style, str, pmosi)
    Window parent_win;
    TidgetInfo *parent_tidgetinfo;
-   int ctl_id, x, y, w, h, h_pad, v_pad, state, font_style;
+   int ctl_id, x, y, w, h, h_pad, v_pad, btn_type, btn_style, state, font_style;
    char *str;
    MouseOverStatusInfo *pmosi;
 {
