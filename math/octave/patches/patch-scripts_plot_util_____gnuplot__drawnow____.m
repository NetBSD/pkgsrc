$NetBSD: patch-scripts_plot_util_____gnuplot__drawnow____.m,v 1.1 2016/02/16 04:21:40 dbj Exp $

We don't currently install libaquaterm on pkgsrc, so making the gnuplot
"aqua" term the default on the mac is unlikely to work.

--- scripts/plot/util/__gnuplot_drawnow__.m.orig	2015-05-23 14:21:53.000000000 +0000
+++ scripts/plot/util/__gnuplot_drawnow__.m
@@ -351,7 +351,7 @@ function term = gnuplot_default_term (pl
   if (isempty (term) || ! __gnuplot_has_terminal__ (term, plot_stream))
     if (isguirunning () && __gnuplot_has_terminal__ ("qt", plot_stream))
       term = "qt";
-    elseif (ismac ())
+    elseif (0 && ismac ()) ## disabled in pkgsrc because libaquaterm is not installed
       term = "aqua";
     elseif (! isunix ())
       term = "windows";
