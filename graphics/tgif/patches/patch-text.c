$NetBSD: patch-text.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora 

--- text.c.orig	2011-06-14 02:24:15.000000000 +0000
+++ text.c
@@ -2071,7 +2071,7 @@ void HandleClickOnText(drag, from_cursor
       pressed_in_same_text, obj_ptr, double_clicked, saved_text_highlight,
       skip_post_processing, click_time)
    int drag, from_cursor_keys, x_off, y_off, pressed_in_same_text;
-   int double_clicked, saved_text_highlight;
+   int double_clicked, saved_text_highlight, skip_post_processing;
    struct ObjRec *obj_ptr;
    Time click_time;
 {
@@ -4772,7 +4772,7 @@ int ReadTextLines(FP, ObjPtr, text_ptr,
    char *color_str;
    int num_lines, has_ps_bitmap, cur_sb_font, cur_db_font;
    int double_byte, db_mod_bytes, db_vertical, direction;
-   int x, baseline_y, *pn_max_len, *pn_max_h;
+   int x, baseline_y, text_w, *pn_max_len, *pn_max_h;
    /*
     * (Note: text_w is only used for fileVersion <= 36)
     */
