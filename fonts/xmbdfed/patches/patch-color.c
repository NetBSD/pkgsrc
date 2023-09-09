$NetBSD: patch-color.c,v 1.1 2023/09/09 14:56:28 vins Exp $

Fix signedness mismatch warnings.

--- color.c.orig	2004-01-29 17:15:37.000000000 +0000
+++ color.c
@@ -28,6 +28,7 @@ static char rcsid[] = "$Id: color.c,v 1.
 #endif
 
 #include <stdio.h>
+#include <stdint.h>
 #include <string.h>
 #include <stdlib.h>
 #include <X11/IntrinsicP.h>
@@ -233,7 +234,7 @@ XtPointer client_data, call_data;
      */
 
     cb = (XmScaleCallbackStruct *) call_data;
-    which = (int) client_data;
+    which = (intptr_t) client_data;
 
     cmap = XDefaultColormap(XtDisplay(w),
                             XDefaultScreen(XtDisplay(w)));
@@ -430,9 +431,9 @@ BuildColorDialog()
         colors.slide[i] = XtCreateManagedWidget("", xmScaleWidgetClass, rc,
                                                 av, ac);
         XtAddCallback(colors.slide[i], XmNvalueChangedCallback, AdjustColor,
-                      (XtPointer) i);
+                      (XtPointer) (intptr_t) i);
         XtAddCallback(colors.slide[i], XmNdragCallback, AdjustColor,
-                      (XtPointer) i);
+                      (XtPointer) (intptr_t) i);
     }
 }
 
