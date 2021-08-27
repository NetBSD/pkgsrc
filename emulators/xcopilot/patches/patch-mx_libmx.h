$NetBSD: patch-mx_libmx.h,v 1.1 2021/08/27 03:41:41 ryoon Exp $

* Declare int as return value type explicitly.

--- mx/libmx.h.orig	1998-08-22 14:46:10.000000000 +0000
+++ mx/libmx.h
@@ -280,7 +280,7 @@ typedef struct _mx_button {
   unsigned int value;		/* bitmap of button states */
 } mx_button;
 
-extern mx_popup_button(Display *display, int screen, mx_panel *panel,
+extern int mx_popup_button(Display *display, int screen, mx_panel *panel,
 		       unsigned int value, int *x, int *y);
 /*****************************************************************************
 
