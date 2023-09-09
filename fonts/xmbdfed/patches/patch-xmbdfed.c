$NetBSD: patch-xmbdfed.c,v 1.1 2023/09/09 14:56:28 vins Exp $

Fix signedness mismatch warnings.

--- xmbdfed.c.orig	2004-02-08 23:59:00.000000000 +0000
+++ xmbdfed.c
@@ -28,6 +28,7 @@ static char rcsid[] = "$Id: xmbdfed.c,v 
 #endif
 
 #include <stdio.h>
+#include <stdint.h>
 #include <string.h>
 #include <stdlib.h>
 #include <X11/cursorfont.h>
@@ -919,7 +920,7 @@ XtPointer client_data, call_data;
 #endif
 {
     Widget fstext;
-    int flags = (int) client_data;
+    int flags = (intptr_t) client_data;
     int pos1, pos2;
     XmString s;
     char *suff, *sp, *ep;
@@ -5303,26 +5304,26 @@ _XmBDFEditorSetup()
      * in the normal fashion.
      */
     cmdres[0].default_addr =
-        (XtPointer) xmbdfed_opts.font_opts.correct_metrics;
+        (XtPointer) (intptr_t) xmbdfed_opts.font_opts.correct_metrics;
     cmdres[1].default_addr =
-        (XtPointer) xmbdfed_opts.font_opts.keep_unencoded;
+        (XtPointer) (intptr_t) xmbdfed_opts.font_opts.keep_unencoded;
     cmdres[2].default_addr =
-        (XtPointer) xmbdfed_opts.font_opts.keep_comments;
+        (XtPointer) (intptr_t) xmbdfed_opts.font_opts.keep_comments;
 
-    cmdres[3].default_addr = (XtPointer) xmbdfed_opts.font_opts.pad_cells;
-    cmdres[4].default_addr = (XtPointer) xmbdfed_opts.font_opts.point_size;
-    cmdres[5].default_addr = (XtPointer) xmbdfed_opts.font_opts.resolution_x;
-    cmdres[6].default_addr = (XtPointer) xmbdfed_opts.font_opts.resolution_y;
-    cmdres[7].default_addr = (XtPointer) xmbdfed_opts.font_opts.font_spacing;
-    cmdres[8].default_addr = (XtPointer) xmbdfed_opts.font_opts.bits_per_pixel;
-    cmdres[9].default_addr = (XtPointer) xmbdfed_opts.font_opts.eol;
-    cmdres[10].default_addr = (XtPointer) xmbdfed_opts.resolution;
-    cmdres[11].default_addr = (XtPointer) xmbdfed_opts.no_blanks;
-    cmdres[12].default_addr = (XtPointer) xmbdfed_opts.really_exit;
-    cmdres[13].default_addr = (XtPointer) xmbdfed_opts.overwrite_mode;
-    cmdres[14].default_addr = (XtPointer) xmbdfed_opts.initial_glyph;
-    cmdres[15].default_addr = (XtPointer) xmbdfed_opts.progbar;
-    cmdres[16].default_addr = (XtPointer) xmbdfed_opts.code_base;
+    cmdres[3].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.font_opts.pad_cells;
+    cmdres[4].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.font_opts.point_size;
+    cmdres[5].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.font_opts.resolution_x;
+    cmdres[6].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.font_opts.resolution_y;
+    cmdres[7].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.font_opts.font_spacing;
+    cmdres[8].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.font_opts.bits_per_pixel;
+    cmdres[9].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.font_opts.eol;
+    cmdres[10].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.resolution;
+    cmdres[11].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.no_blanks;
+    cmdres[12].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.really_exit;
+    cmdres[13].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.overwrite_mode;
+    cmdres[14].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.initial_glyph;
+    cmdres[15].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.progbar;
+    cmdres[16].default_addr = (XtPointer) (intptr_t) xmbdfed_opts.code_base;
 }
 
 int
