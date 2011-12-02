$NetBSD: patch-report.pl,v 1.1 2011/12/02 15:31:44 hauke Exp $

--- report.pl.orig	2011-12-02 13:57:45.000000000 +0000
+++ report.pl
@@ -103,11 +103,11 @@ set ytics
 set logscale x 2
 set logscale y 2
 set autoscale z
-set xrange [2.**5:2.**24]
+#set xrange [2.**5:2.**24]
 set xlabel "File size in KBytes"
 set ylabel "Record size in Kbytes"
 set zlabel "Kbytes/sec"
-set data style lines
+set style data lines
 set dgrid3d 80,80,3
 #set terminal png small picsize 900 700
 set terminal png small size 900 700
