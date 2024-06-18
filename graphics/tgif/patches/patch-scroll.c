$NetBSD: patch-scroll.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora 

--- scroll.c.orig	2011-05-16 16:21:59.000000000 +0000
+++ scroll.c
@@ -165,7 +165,8 @@ int TgPressButtonLoop(dpy, win, pbbox, p
 
 int TgGetScrollHit(x, y, orientation, scroll_area_w, scroll_area_h,
       start_frac, length, total, pn_btn_offset)
-   int x, y, scroll_area_w, scroll_area_h, length, total, *pn_btn_offset;
+   int x, y, orientation, scroll_area_w, scroll_area_h, length, total,
+   	*pn_btn_offset;
    double start_frac;
 {
    int block_start=0, block_size=0, min_block_size=1+(windowPadding<<1);
@@ -223,7 +224,7 @@ void TgDrawScrollBar(dpy, win, orientati
       scroll_area_h, start_frac, length, total)
    Display *dpy;
    Window win;
-   int x_off, y_off, scroll_area_w, scroll_area_h, length, total;
+   int orientation, x_off, y_off, scroll_area_w, scroll_area_h, length, total;
    double start_frac;
 {
    int block_start=0, block_size=0, min_block_size=1+(windowPadding<<1);
