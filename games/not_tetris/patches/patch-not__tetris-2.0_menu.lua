$NetBSD: patch-not__tetris-2.0_menu.lua,v 1.1 2024/01/19 02:34:30 maya Exp $

Avoid uninitialized oldtime
Prevent startup crash

--- not_tetris_archive/menu.lua.orig	2024-01-19 02:26:25.027517359 +0000
+++ not_tetris_archive/menu.lua
@@ -1,3 +1,4 @@
+oldtime = 0
 function menu_load()
 	gamestate = "logo"
 	creditstext = {
@@ -284,4 +285,4 @@ function menu_update(dt)
 			end
 		end
 	end
-end
\ No newline at end of file
+end
