$NetBSD: patch-w__export.c,v 1.1 2012/12/24 21:12:36 joerg Exp $

--- w_export.c.orig	2012-12-23 17:39:22.000000000 +0000
+++ w_export.c
@@ -1016,7 +1016,7 @@ toggle_hpgl_pcl_switch(Widget w, XtPoint
     /* set global state */
     print_hpgl_pcl_switch = state;
 
-    return;
+    return 0;
 }
 
 static XtCallbackProc
@@ -1038,7 +1038,7 @@ toggle_hpgl_font(Widget w, XtPointer clo
     /* set global state */
     hpgl_specified_font = state;
 
-    return;
+    return 0;
 }
 
 void create_export_panel(Widget w)
