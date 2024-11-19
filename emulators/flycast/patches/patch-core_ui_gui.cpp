$NetBSD: patch-core_ui_gui.cpp,v 1.1 2024/11/19 14:58:05 nia Exp $

Around these parts, we run Unix.

--- core/ui/gui.cpp.orig	2024-11-19 14:34:33.973890750 +0000
+++ core/ui/gui.cpp
@@ -2867,7 +2867,7 @@ static void gui_settings_about()
 #ifdef __ANDROID__
 			"Android"
 #elif defined(__unix__)
-			"Linux"
+			"Unix"
 #elif defined(__APPLE__)
 #ifdef TARGET_IPHONE
     		"iOS"
