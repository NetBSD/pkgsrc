$NetBSD: patch-build_premake_extern__libs5.lua,v 1.2 2023/05/05 14:55:18 nikita Exp $

pkgsrc miniupnpc is new enough to have pkg-config files.
get iconv from libc on FreeBSD and NetBSD.

--- build/premake/extern_libs5.lua.orig	2022-08-21 14:45:49.000000000 +0200
+++ build/premake/extern_libs5.lua	2023-05-05 14:04:01.320479087 +0200
@@ -372,7 +372,7 @@
 			elseif os.istarget("macosx") then
 				add_default_include_paths("iconv")
 				defines { "LIBICONV_STATIC" }
-			elseif os.getversion().description == "FreeBSD" then
+			elseif os.getversion().description == "NetBSD" or os.getversion().description == "FreeBSD" then
 				-- On FreeBSD you need this flag to tell it to use the BSD libc iconv
 				defines { "LIBICONV_PLUG" }
 			end
@@ -525,14 +525,13 @@
 				add_default_links({
 					win_names  = { "miniupnpc" },
 				})
-			elseif os.istarget("macosx") then
-				pkgconfig.add_links("miniupnpc")
 			else
+				pkgconfig.add_links("miniupnpc")
 				-- Once miniupnpc v2.1 or better becomes near-universal (see above comment),
 				-- we can use pkg-config for Linux and BSD.
-				add_default_links({
-					unix_names = { "miniupnpc" },
-				})
+				--add_default_links({
+				--	unix_names = { "miniupnpc" },
+				--})
 			end
 		end,
 	},
