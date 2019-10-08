$NetBSD: patch-kobo.cpp,v 1.1 2019/10/08 16:13:12 ryoon Exp $

* Fix immediate pause
  From https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=909244

--- kobo.cpp.orig	2007-12-24 05:59:02.000000000 +0000
+++ kobo.cpp
@@ -1691,7 +1691,7 @@ void kobo_gfxengine_t::frame()
 			break;
 		  case SDL_ACTIVEEVENT:
 			// Any type of focus loss should activate pause mode!
-			if(!ev.active.gain)
+			if(!ev.active.gain && ev.active.state != SDL_APPINPUTFOCUS)
 				km.pause_game();
 			break;
 		  case SDL_QUIT:
