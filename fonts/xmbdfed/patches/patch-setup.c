$NetBSD: patch-setup.c,v 1.1 2023/09/09 14:56:28 vins Exp $

Fix signedness mismatch warnings.

--- setup.c.orig	2004-02-12 15:29:17.000000000 +0000
+++ setup.c
@@ -28,6 +28,7 @@ static char rcsid[] = "$Id: setup.c,v 1.
 #endif
 
 #include <stdio.h>
+#include <stdint.h>
 #include <string.h>
 #include <stdlib.h>
 #include <X11/IntrinsicP.h>
@@ -371,7 +372,7 @@ XtPointer client_data, call_data;
     int which;
     XmToggleButtonCallbackStruct *cb;
 
-    which = (int) client_data;
+    which = (intptr_t) client_data;
     cb = (XmToggleButtonCallbackStruct *) call_data;
 
     if (which == 1) {
@@ -395,7 +396,7 @@ Widget w;
 XtPointer client_data, call_data;
 #endif
 {
-    setup.pixsize = (int) client_data;
+    setup.pixsize = (intptr_t) client_data;
     XtSetSensitive(setup.update, True);
 }
 
@@ -408,8 +409,8 @@ Widget w;
 XtPointer client_data, call_data;
 #endif
 {
-    if ((setup.bpp = (int) client_data) > 1) {
-        xmbdfedAllocateColors(top, (int) client_data);
+    if ((setup.bpp = (intptr_t) client_data) > 1) {
+        xmbdfedAllocateColors(top, (intptr_t) client_data);
         XtSetSensitive(setup.colors, True);
     } else
       XtSetSensitive(setup.colors, False);
@@ -425,7 +426,7 @@ Widget w;
 XtPointer client_data, call_data;
 #endif
 {
-    setup.eol = (int) client_data;
+    setup.eol = (intptr_t) client_data;
     XtSetSensitive(setup.update, True);
 }
 
@@ -443,7 +444,7 @@ XtPointer client_data, call_data;
     char *path;
     XmFileSelectionBoxCallbackStruct *cb;
 
-    adobe = (int) client_data;
+    adobe = (intptr_t) client_data;
 
     cb = (XmFileSelectionBoxCallbackStruct *) call_data;
     XmStringGetLtoR(cb->value, XmSTRING_DEFAULT_CHARSET, &path);
@@ -498,7 +499,7 @@ XtPointer client_data, call_data;
     XtCallbackList cl;
     Arg av[1];
 
-    adobe = (int) client_data;
+    adobe = (intptr_t) client_data;
 
     if (other.fsel == 0) {
         other.fsel = XmCreateFileSelectionDialog(top,
@@ -734,7 +735,7 @@ XtPointer client_data, call_data;
                 XtCreateManagedWidget(name, xmPushButtonWidgetClass, pdown,
                                       0, 0);
             XtAddCallback(pb, XmNactivateCallback, SetPixelSize,
-                          (XtPointer) i);
+                          (XtPointer) (intptr_t) i);
             if (i == xmbdfed_opts.pixel_size) {
                 XtSetArg(av[0], XmNmenuHistory, pb);
                 XtSetValues(opts, av, 1);
