$NetBSD: patch-libs_gtkmm2ext_fastmeter.cc,v 1.1 2016/12/15 23:45:07 joerg Exp $

Use bool conversion, RefPtr doesn't compare to 0 in C++11 mode.

--- libs/gtkmm2ext/fastmeter.cc.orig	2016-12-15 17:10:48.369372136 +0000
+++ libs/gtkmm2ext/fastmeter.cc
@@ -731,7 +731,7 @@ FastMeter::set (float lvl, float peak)
 
 	Glib::RefPtr<Gdk::Window> win;
 
-	if ((win = get_window()) == 0) {
+	if (!(win = get_window())) {
 		queue_draw ();
 		return;
 	}
