$NetBSD: patch-stretch.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora 

--- stretch.c.orig	2011-05-16 16:21:59.000000000 +0000
+++ stretch.c
@@ -4260,7 +4260,7 @@ void SizeAnObj(ObjPtr, TopOwner, AbsW, A
 
 static
 void DoSizeAllSelToGivenWidthHeight(abs_w, abs_h, do_width, do_height)
-   int abs_h, do_width, do_height;
+   int abs_w, abs_h, do_width, do_height;
 {
    struct SelRec *saved_top_sel=topSel, *saved_bot_sel=botSel, *sel_ptr=NULL;
    int saved_h_align=horiAlign, saved_v_align=vertAlign, num_to_resize=0;
