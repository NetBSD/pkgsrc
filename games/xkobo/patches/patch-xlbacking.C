$NetBSD: patch-xlbacking.C,v 1.1 2012/05/27 18:16:32 abs Exp $

--- xlbacking.C.orig	1996-03-13 16:34:42.000000000 +0000
+++ xlbacking.C
@@ -21,6 +21,7 @@
  */
 
 #include "xlbacking.h"
+#include <stdio.h>
 
 //--------------------------------------------------------------------------//
 //                     class     win_backing                                //
@@ -104,7 +105,16 @@ void win_backing::background(int i)
 
 void win_backing::font(char *s)
 {
-    Font f1 = XLoadFont(disp,s);
+    char **fontnames;
+    int found;    
+    Font f1;
+
+    fontnames = XListFonts(disp, s, 1, &found);
+    XFreeFontNames(fontnames);
+    if (!found)
+	fprintf(stderr, "xkobo : font '%s' missing, using fixed\n", s);
+
+    f1 = XLoadFont(disp, found ? s : "fixed");
     XSetFont(disp,gc,f1);
 }
 
