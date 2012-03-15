$NetBSD: patch-share_lua_website_youtube.lua,v 1.1 2012/03/15 16:01:47 wiz Exp $

Fix some youtube URLs.
From upstream:
http://sourceforge.net/mailarchive/message.php?msg_id=28987218

--- share/lua/website/youtube.lua.orig	2011-11-29 14:37:43.000000000 +0000
+++ share/lua/website/youtube.lua
@@ -81,7 +81,7 @@ function YouTube.normalize(s)
         local p = {'/embed/([-_%w]+)', '/%w/([-_%w]+)', '/([-_%w]+)'}
         for _,v in pairs(p) do
             local m = t.path:match(v)
-            if m and not t.query then
+            if m and #m == 11 then
                 t.query = 'v=' .. m
                 t.path  = '/watch'
             end
