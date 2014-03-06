$NetBSD: patch-scripts_plot_daspect.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/plot/daspect.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/plot/daspect.m
@@ -18,22 +18,23 @@
 
 ## -*- texinfo -*-
 ## @deftypefn {Function File} {} daspect (@var{data_aspect_ratio})
-## Set the data aspect ratio of the current axes.  The aspect ratio is
-## a normalized 3-element vector representing the span of the x, y, and
-## z-axes limits.
-##
-## @deftypefnx {Function File} {@var{data_aspect_ratio} =} daspect ( )
-## Return the data aspect ratio of the current axes.
-##
+## @deftypefnx {Function File} {@var{data_aspect_ratio} =} daspect ()
 ## @deftypefnx {Function File} {} daspect (@var{mode})
-## Set the data aspect ratio mode of the current axes.
-##
 ## @deftypefnx {Function File} {@var{data_aspect_ratio_mode} =} daspect ("mode")
-## Return the data aspect ratio mode of the current axes.
-##
 ## @deftypefnx {Function File} {} daspect (@var{hax}, @dots{})
-## Use the axes, with handle @var{hax}, instead of the current axes.
-##
+## @code{daspect} sets the data aspect ratio of the current axes.  The aspect 
+## ratio is a normalized 3-element vector representing the span of the x, y, and
+## z-axes limits.
+## 
+## When called without any arguments it returns data aspect ratio of the current axes.
+## 
+## @code{(daspect (@var{mode}))} sets the data aspect ratio mode of the current axes.
+## 
+## @code{daspect ("mode")} returns the data aspect ratio mode of the current axes.
+## 
+## @code{daspect (@var{hax}, @dots{})} uses the axes, with handle @var{hax},
+## instead of the current axes.
+## 
 ## @seealso{axis, pbaspect, xlim, ylim, zlim}
 ## @end deftypefn
 
