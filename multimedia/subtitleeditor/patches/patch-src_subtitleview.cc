$NetBSD: patch-src_subtitleview.cc,v 1.1 2015/11/03 19:04:57 joerg Exp $

--- src/subtitleview.cc.orig	2015-11-03 11:47:27.000000000 +0000
+++ src/subtitleview.cc
@@ -1393,7 +1393,7 @@ bool SubtitleView::on_key_press_event(Gd
 	{
 		int num;
 		std::istringstream ss(event->string);
-		bool is_num = ss >> num != 0; 
+		bool is_num(ss >> num); 
 		// Update only if it's different
 		if(is_num != get_enable_search())
 			set_enable_search(is_num);
