$NetBSD: patch-gtk2__ardour_fft__graph.cc,v 1.1 2016/12/15 23:45:07 joerg Exp $

Use bool conversion, RefPtr doesn't compare to 0 in C++11 mode.

--- gtk2_ardour/fft_graph.cc.orig	2016-12-15 17:21:24.763867051 +0000
+++ gtk2_ardour/fft_graph.cc
@@ -203,7 +203,7 @@ FFTGraph::draw_scales(Glib::RefPtr<Gdk::
 
 
 
-	if (graph_gc == 0) {
+	if (!graph_gc) {
 		graph_gc = GC::create( get_window() );
 	}
 
@@ -213,7 +213,7 @@ FFTGraph::draw_scales(Glib::RefPtr<Gdk::
 
 	graph_gc->set_rgb_fg_color( grey );
 
-	if (layout == 0) {
+	if (!layout) {
 		layout = create_pango_layout ("");
 		layout->set_font_description (get_style()->get_font());
 	}
