$NetBSD: patch-contrib_xwintoppm_multiVis.c,v 1.1 2013/08/17 14:39:24 taca Exp $

* Add missing parameter declartion.

--- contrib/xwintoppm/multiVis.c.orig	1998-02-13 07:48:33.000000000 +0000
+++ contrib/xwintoppm/multiVis.c
@@ -982,6 +982,7 @@ static void add_window_to_list( image_wi
     int 	y_vis;
     int 	width;
     int 	height;
+    int		border_width;
     Visual	*vis;
     Colormap	cmap;
     Window	parent;
