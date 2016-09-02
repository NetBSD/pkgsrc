$NetBSD: patch-scripts_genie.lua,v 1.4 2016/09/02 12:22:46 wiz Exp $

Precompilation is broken on NetBSD with gcc-5.3.
Use GNU version of the C++ standard to avoid trouble with alloca on NetBSD.
Detect clang correctly.

--- scripts/genie.lua.orig	2016-04-27 06:13:59.000000000 +0000
+++ scripts/genie.lua
@@ -65,11 +65,6 @@ function layoutbuildtask(_folder, _name)
 end
 
 function precompiledheaders()
-	if _OPTIONS["precompile"]==nil or (_OPTIONS["precompile"]~=nil and _OPTIONS["precompile"]=="1") then
-		configuration { "not xcode4" }
-			pchheader("emu.h")
-		configuration { }
-	end
 end
 
 function addprojectflags()
@@ -692,22 +687,22 @@ local version = str_to_version(_OPTIONS[
 if string.find(_OPTIONS["gcc"], "clang") and ((version < 30500) or (_OPTIONS["targetos"]=="macosx" and (version <= 60000))) then
 	buildoptions_cpp {
 		"-x c++",
-		"-std=c++1y",
+		"-std=gnu++1y",
 	}
 
 	buildoptions_objc {
 		"-x objective-c++",
-		"-std=c++1y",
+		"-std=gnu++1y",
 	}
 else
 	buildoptions_cpp {
 		"-x c++",
-		"-std=c++14",
+		"-std=gnu++14",
 	}
 
 	buildoptions_objc {
 		"-x objective-c++",
-		"-std=c++14",
+		"-std=gnu++14",
 	}
 end
 -- this speeds it up a bit by piping between the preprocessor/compiler/assembler
