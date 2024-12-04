$NetBSD: patch-Pixmap.c,v 1.2 2024/12/04 10:40:37 nros Exp $

Fix implicit function declaration of exit.

Use bundled version of rgb.c since libxpm
does make the xpm* function names visible
anymore.

--- Pixmap.c.orig	2024-12-02 10:40:36.762246945 +0000
+++ Pixmap.c
@@ -65,8 +65,10 @@ static char rcsid[] = "$Id: Pixmap.c,v 1
 #include <X11/cursorfont.h>
 #define AVOID    /* Avoid some clashing prototyping in Pixmap.h */
 #include "PixmapP.h"
+#include "rgb.h"
     
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
 
 #define XtStrlen(s)                   ((s) ? strlen(s) : 0)
@@ -84,17 +86,8 @@ static int max_ncolors = -1;
 
 /* picked up from rgb.c of Xpm lib */
 static char *rgb_fname = RGBF ;
-#ifndef UNUSE_XPM
-typedef struct {  /* rgb values and ascii names (from rgb text file) */
-   int  r, g, b;  /* rgb values, range of 0 -> 65535 */
-   char *name;    /* color mnemonic of rgb value */
-} RgbName;
-#define MAX_RGBNAMES 1024
-#endif /* UNUSE_XPM */
-static RgbName rgb_table[MAX_RGBNAMES];
+static xpmRgbName rgb_table[MAX_RGBNAMES];
 
-extern int xpmReadRgbNames();
-extern char *xpmGetRgbName();
 
 #define DefaultGridTolerance 5
 #define DefaultPixmapWidth   32
@@ -1142,7 +1135,7 @@ static void Initialize(request, new, arg
     depth = DefaultDepth(dpy,screen);
 
     if (max_ncolors == -1)
-      max_ncolors = xpmReadRgbNames(rgb_fname, rgb_table);
+      max_ncolors = pm_xpmReadRgbNames(rgb_fname, rgb_table);
 
     /* allocate max colors + 1 colorTable entries because 0 is transparent */
     if (depth <= MAX_DEPTH) {
@@ -1703,7 +1696,7 @@ void PWUpdateColorInTable(w, pixel, symb
 
 	  xcolor.pixel = pixel;
 	  XQueryColor(dpy, PW->core.colormap, &xcolor);
-	  rgb_name = xpmGetRgbName(rgb_table, max_ncolors, 
+	  rgb_name = pm_xpmGetRgbName(rgb_table, max_ncolors, 
 				   (int) xcolor.red, 
 				   (int) xcolor.green, 
 				   (int) xcolor.blue);
@@ -1722,7 +1715,7 @@ void PWUpdateColorInTable(w, pixel, symb
       xcolor.pixel = pixel;
       XQueryColor(dpy, PW->core.colormap, &xcolor);
       
-      if (!(rgb_name = xpmGetRgbName(rgb_table, max_ncolors,
+      if (!(rgb_name = pm_xpmGetRgbName(rgb_table, max_ncolors,
 				     (int) xcolor.red,
 				     (int) xcolor.green,
 				     (int) xcolor.blue)))
