$NetBSD: patch-scripts_plot_print.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/plot/print.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/plot/print.m
@@ -184,11 +184,11 @@
 ## is sent to a file the size is determined by the plot box defined by
 ## the figure's "paperposition" property.
 ##
-## @itemx -append
+## @item -append
 ##   Appends the PS, or PDF output to a pre-existing file of the
 ## same type.
 ##
-## @itemx -r@var{NUM}
+## @item -r@var{NUM}
 ##   Resolution of bitmaps in pixels per inch.  For both metafiles and
 ## SVG the default is the screen resolution, for other it is 150 dpi.
 ## To specify screen resolution, use "-r0".
