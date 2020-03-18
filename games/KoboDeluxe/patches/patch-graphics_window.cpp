$NetBSD: patch-graphics_window.cpp,v 1.1 2020/03/18 17:54:54 joerg Exp $

--- graphics/window.cpp.orig	2020-03-18 13:31:58.788125295 +0000
+++ graphics/window.cpp
@@ -398,7 +398,7 @@ void window_t::center_token_fxp(int _x, 
 		 */
 		if(token)
 		{
-			char *tok = strchr(txt, token);
+			const char *tok = strchr(txt, token);
 			if(tok)
 				tokpos = tok-txt;
 			else
