$NetBSD: patch-graphics_window.cpp,v 1.2 2025/08/16 20:55:51 triaxx Exp $

Fix invalide pointer substraction since pointers was of different types.

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
