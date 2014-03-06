$NetBSD: patch-scripts_plot_pbaspect.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/plot/pbaspect.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/plot/pbaspect.m
@@ -18,21 +18,24 @@
 
 ## -*- texinfo -*-
 ## @deftypefn {Function File} {} pbaspect (@var{plot_box_aspect_ratio})
-## Set the plot box aspect ratio of the current axes.  The aspect ratio
-## is a normalized 3-element vector representing the rendered lengths of
-## the x, y, and z-axes.
-##
 ## @deftypefnx {Function File} {@var{plot_box_aspect_ratio} =} pbaspect ( )
-## Return the plot box aspect ratio of the current axes.
-##
 ## @deftypefnx {Function File} {} pbaspect (@var{mode})
-## Set the plot box aspect ratio mode of the current axes.
-##
 ## @deftypefnx {Function File} {@var{plot_box_aspect_ratio_mode} =} pbaspect ("mode")
-## Return the plot box aspect ratio mode of the current axes.
-##
 ## @deftypefnx {Function File} {} pbaspect (@var{hax}, @dots{})
-## Use the axes, with handle @var{hax}, instead of the current axes.
+## 
+## Set the plot box aspect ratio of the current axes.  The aspect ratio
+## is a normalized 3-element vector representing the rendered lengths of
+## the x, y, and z-axes.
+## 
+## When called without any arguments, returns the plot box aspect ratio of 
+## the current axes.
+## 
+## @code{pbaspect(@var{mode})} sets the plot box aspect ratio mode of the current axes.
+## 
+## @code{pbaspect ("mode")} returns the plot box aspect ratio mode of the current axes.
+## 
+## @code{pbaspect (@var{hax}, @dots{})} uses the axes, with handle @var{hax}, instead 
+## of the current axes.
 ##
 ## @seealso{axis, daspect, xlim, ylim, zlim}
 ## @end deftypefn
