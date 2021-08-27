$NetBSD: patch-mx_buttons.h,v 1.1 2021/08/27 03:41:41 ryoon Exp $

* Declare int as return value type explicitly.

--- mx/buttons.h.orig	1998-04-25 17:50:14.000000000 +0000
+++ mx/buttons.h
@@ -29,5 +29,5 @@ typedef struct _mx_button {
   unsigned int value;		/* bitmap of button states */
 } mx_button;
 
-extern mx_popup_button(Display *display, int screen, mx_panel *panel,
+extern int mx_popup_button(Display *display, int screen, mx_panel *panel,
 		       unsigned int value, int *x, int *y);
