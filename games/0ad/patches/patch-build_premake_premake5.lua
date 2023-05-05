$NetBSD: patch-build_premake_premake5.lua,v 1.1 2023/05/05 14:55:18 nikita Exp $


--- build/premake/premake5.lua.orig	2023-05-05 11:58:04.687082368 +0200
+++ build/premake/premake5.lua	2023-05-05 12:03:48.476951617 +0200
@@ -386,7 +386,7 @@
 			-- To use our local shared libraries, they need to be found in the
 			-- runtime dynamic linker path. Add their path to -rpath.
 			if _OPTIONS["libdir"] then
-				linkoptions {"-Wl,-rpath," .. _OPTIONS["libdir"] }
+				linkoptions {"-Wl,-rpath," .. _OPTIONS["libdir"] .. " -Wl,-rpath,@@PREFIXLIB@@"}
 			else
 				-- On FreeBSD we need to allow use of $ORIGIN
 				if os.istarget("bsd") then
