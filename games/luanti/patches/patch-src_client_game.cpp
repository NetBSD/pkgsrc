$NetBSD: patch-src_client_game.cpp,v 1.2 2026/02/10 02:06:36 ktnb Exp $

Temporary fix for bug with SDL.
https://github.com/luanti-org/luanti/issues/16199

--- src/client/game.cpp.orig	2026-02-08 11:42:38.000000000 +0000
+++ src/client/game.cpp
@@ -1927,8 +1927,8 @@ void Game::updateCameraDirection(CameraO
 	Since we have our own code to synthesize mouse events from touch events,
 	this results in duplicated input. To avoid that, we don't enable relative
 	mouse mode if we're in touchscreen mode. */
-	if (cur_control)
-		cur_control->setRelativeMode(!g_touchcontrols && !isMenuActive());
+//	if (cur_control)
+//		cur_control->setRelativeMode(!g_touchcontrols && !isMenuActive());
 
 	if ((device->isWindowActive() && device->isWindowFocused()
 			&& !isMenuActive()) || input->isRandom()) {
