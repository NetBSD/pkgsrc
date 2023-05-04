$NetBSD: patch-build_premake_extern__libs5.lua,v 1.1 2023/05/04 15:20:52 nikita Exp $

--- build/premake/extern_libs5.lua.orig	2021-07-27 21:57:08.000000000 +0000
+++ build/premake/extern_libs5.lua
@@ -350,7 +350,7 @@ extern_lib_defs = {
 			elseif os.istarget("macosx") then
 				add_default_include_paths("iconv")
 				defines { "LIBICONV_STATIC" }
-			elseif os.getversion().description == "FreeBSD" then
+			elseif os.getversion().description == "NetBSD" then
 				-- On FreeBSD you need this flag to tell it to use the BSD libc iconv
 				defines { "LIBICONV_PLUG" }
 			end
