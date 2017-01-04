$NetBSD: patch-scripts_genie.lua,v 1.6 2017/01/04 23:05:12 wiz Exp $

Precompilation is broken on NetBSD with gcc-5.3.
Use GNU version of the C++ standard to avoid trouble with alloca on NetBSD.

--- scripts/genie.lua.orig	2016-12-27 21:02:43.000000000 +0000
+++ scripts/genie.lua
@@ -70,11 +70,6 @@ function layoutbuildtask(_folder, _name)
 end
 
 function precompiledheaders()
-	if _OPTIONS["precompile"]==nil or (_OPTIONS["precompile"]~=nil and _OPTIONS["precompile"]=="1") then
-		configuration { "not xcode4" }
-			pchheader("emu.h")
-		configuration { }
-	end
 end
 
 function addprojectflags()
@@ -711,12 +706,12 @@ if string.find(_OPTIONS["gcc"], "clang")
 else
 	buildoptions_cpp {
 		"-x c++",
-		"-std=c++14",
+		"-std=gnu++14",
 	}
 
 	buildoptions_objcpp {
 		"-x objective-c++",
-		"-std=c++14",
+		"-std=gnu++14",
 	}
 end
 -- this speeds it up a bit by piping between the preprocessor/compiler/assembler
