$NetBSD: patch-src_tools_gcc.lua,v 1.2 2025/06/26 09:24:17 triaxx Exp $

Remove the hardcoded -L/usr/lib and -L/usr/lib64
This is not needed, and will cause issues:
https://github.com/gentoo/gentoo/pull/25825#issuecomment-1179497476

--- src/tools/gcc.lua.orig	2022-09-03 20:03:02.000000000 +0000
+++ src/tools/gcc.lua
@@ -544,16 +544,10 @@
 		architecture = {
 			x86 = function (cfg)
 				local r = {}
-				if not table.contains(os.getSystemTags(cfg.system), "darwin") then
-					table.insert (r, "-L/usr/lib32")
-				end
 				return r
 			end,
 			x86_64 = function (cfg)
 				local r = {}
-				if not table.contains(os.getSystemTags(cfg.system), "darwin") then
-					table.insert (r, "-L/usr/lib64")
-				end
 				return r
 			end,
 		},
