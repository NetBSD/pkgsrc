$NetBSD: patch-player-lua-ytdl__hook.lua,v 1.1 2023/03/08 17:39:19 snj Exp $

https://github.com/mpv-player/mpv/commit/94c189dae76ba280d9883b16346c3dfb9720687e

--- player/lua/ytdl_hook.lua.orig	2023-03-08 09:25:20.398346894 -0800
+++ player/lua/ytdl_hook.lua	2023-03-08 09:25:29.108234437 -0800
@@ -295,7 +295,7 @@ local function edl_track_joined(fragment
         local args = ""
 
         -- assume MP4 DASH initialization segment
-        if not fragments[1].duration then
+        if not fragments[1].duration and #fragments > 1 then
             msg.debug("Using init segment")
             args = args .. ",init=" .. edl_escape(join_url(base, fragments[1]))
             offset = 2
