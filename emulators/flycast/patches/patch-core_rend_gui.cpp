$NetBSD: patch-core_rend_gui.cpp,v 1.1 2023/07/02 17:32:30 nia Exp $

Here, we support Unix.

--- core/rend/gui.cpp.orig	2023-02-15 17:59:44.000000000 +0000
+++ core/rend/gui.cpp
@@ -2230,7 +2230,7 @@ static void gui_display_settings()
 #ifdef __ANDROID__
 					"Android"
 #elif defined(__unix__)
-					"Linux"
+					"Unix"
 #elif defined(__APPLE__)
 #ifdef TARGET_IPHONE
 		    		"iOS"
