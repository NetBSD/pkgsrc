$NetBSD: patch-scripts_plot_____gnuplot__drawnow____.m,v 1.1 2015/04/23 06:48:53 dbj Exp $

We don't currently install libaquaterm on pkgsrc, so making the gnuplot
"aqua" term the default on the mac is unlikely to work.

--- scripts/plot/__gnuplot_drawnow__.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/plot/__gnuplot_drawnow__.m
@@ -328,7 +328,7 @@ function term = gnuplot_default_term ()
   term = getenv ("GNUTERM");
   ## If not specified, guess the terminal type.
   if (isempty (term))
-    if (ismac ())
+    if (0 && ismac ()) ## disabled in pkgsrc because libaquaterm is not installed
       term = "aqua";
     elseif (! isunix ())
       term = "windows";
