$NetBSD: patch-scripts_genie.lua,v 1.5 2016/12/25 21:44:35 joerg Exp $

Precompilation is broken on NetBSD with gcc-5.3.
Use GNU version of the C++ standard to avoid trouble with alloca on NetBSD.
Detect clang correctly.

--- scripts/genie.lua.orig	2016-10-25 23:47:23.000000000 +0000
+++ scripts/genie.lua
@@ -66,11 +66,6 @@ function layoutbuildtask(_folder, _name)
 end
 
 function precompiledheaders()
-	if _OPTIONS["precompile"]==nil or (_OPTIONS["precompile"]~=nil and _OPTIONS["precompile"]=="1") then
-		configuration { "not xcode4" }
-			pchheader("emu.h")
-		configuration { }
-	end
 end
 
 function addprojectflags()
@@ -169,6 +164,11 @@ newoption {
 }
 
 newoption {
+	trigger = "clang_version",
+	description = "Clang compiler version",
+}
+
+newoption {
 	trigger = "CC",
 	description = "CC replacement",
 }
@@ -673,22 +673,22 @@ local version = str_to_version(_OPTIONS[
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
@@ -930,9 +930,10 @@ end
 
 
 
-		local version = str_to_version(_OPTIONS["gcc_version"])
-		if string.find(_OPTIONS["gcc"], "clang") or string.find(_OPTIONS["gcc"], "pnacl") or string.find(_OPTIONS["gcc"], "asmjs") or string.find(_OPTIONS["gcc"], "android") then
-			if (version < 30400) then
+		local gcc_version = str_to_version(_OPTIONS["gcc_version"])
+		local clang_version = str_to_version(_OPTIONS["clang_version"])
+		if (clang_version)  then
+			if (clang_version < 30400) then
 				print("Clang version 3.4 or later needed")
 				os.exit(-1)
 			end
@@ -944,7 +945,7 @@ end
 				"-Wno-missing-braces", -- clang is not as permissive as GCC about std::array initialization
 				"-fdiagnostics-show-note-include-stack",
 			}
-			if (version >= 30500) then
+			if (clang_version >= 30500) then
 				buildoptions {
 					"-Wno-unknown-warning-option",
 					"-Wno-extern-c-compat",
@@ -953,7 +954,7 @@ end
 				}
 			end
 		else
-			if (version < 50000) then
+			if (gcc_version < 50000) then
 				print("GCC version 5.0 or later needed")
 				os.exit(-1)
 			end
