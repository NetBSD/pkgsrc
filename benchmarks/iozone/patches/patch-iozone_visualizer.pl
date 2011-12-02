$NetBSD: patch-iozone_visualizer.pl,v 1.1 2011/12/02 15:31:44 hauke Exp $

--- iozone_visualizer.pl.orig	2011-12-02 13:57:45.000000000 +0000
+++ iozone_visualizer.pl
@@ -190,11 +190,11 @@ set ytics $yoffset
 set logscale x 2
 set logscale y 2
 set autoscale z
-set xrange [2.**5:2.**24]
+#set xrange [2.**5:2.**24]
 set xlabel "File size in KBytes" -2
 set ylabel "Record size in Kbytes" 2
 set zlabel "Kbytes/sec" 4,8 
-set data style lines
+set style data lines
 set dgrid3d 80,80,3
 #set terminal png small picsize 900 700
 set terminal png small size $size3d nocrop
