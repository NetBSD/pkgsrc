$NetBSD: patch-scripts_plot_legend.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/plot/legend.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/plot/legend.m
@@ -86,7 +86,7 @@
 ## @item "hide"
 ##   Hide legend on the plot
 ##
-## @itemx "toggle"
+## @item "toggle"
 ##   Toggles between "hide" and "show"
 ##
 ## @item "boxon"
@@ -101,7 +101,7 @@
 ## @item "right"
 ##   Place text to the right of the keys
 ##
-## @itemx "off"
+## @item "off"
 ##   Delete the legend object
 ## @end table
 ## @end deftypefn
