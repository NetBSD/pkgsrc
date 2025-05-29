$NetBSD: patch-src_client_game.cpp,v 1.1 2025/05/29 17:36:03 ktnb Exp $

Temporary fix for bug with SDL.
https://github.com/luanti-org/luanti/issues/16199

--- src/client/game.cpp.orig	2025-05-29 12:58:05.749735811 +0000
+++ src/client/game.cpp
@@ -2432,8 +2432,8 @@ void Game::updateCameraDirection(CameraO
 	Since Minetest has its own code to synthesize mouse events from touch events,
 	this results in duplicated input. To avoid that, we don't enable relative
 	mouse mode if we're in touchscreen mode. */
-	if (cur_control)
-		cur_control->setRelativeMode(!g_touchcontrols && !isMenuActive());
+//	if (cur_control)
+//		cur_control->setRelativeMode(!g_touchcontrols && !isMenuActive());
 
 	if ((device->isWindowActive() && device->isWindowFocused()
 			&& !isMenuActive()) || input->isRandom()) {
