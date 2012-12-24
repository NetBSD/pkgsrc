$NetBSD: patch-w__print.c,v 1.1 2012/12/24 21:12:36 joerg Exp $

--- w_print.c.orig	2012-12-23 17:41:12.000000000 +0000
+++ w_print.c
@@ -1185,7 +1185,7 @@ switch_print_layers(Widget w, XtPointer 
     /* which button */
     which = (int) XawToggleGetCurrent(w);
     if (which == 0)		/* no buttons on, in transition so return now */
-	return;
+	return 0;
     if (which == 2)		/* "blank" button, invert state */
 	state = !state;
 
@@ -1193,7 +1193,7 @@ switch_print_layers(Widget w, XtPointer 
     print_all_layers = state;
     update_figure_size();
 
-    return;
+    return 0;
 }
 
 /* when user toggles between printing all or only active layers */
