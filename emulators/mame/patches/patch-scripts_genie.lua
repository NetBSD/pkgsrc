$NetBSD: patch-scripts_genie.lua,v 1.3 2016/04/29 08:30:50 wiz Exp $

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
@@ -950,7 +945,17 @@ end
 
 
 		local version = str_to_version(_OPTIONS["gcc_version"])
-		if string.find(_OPTIONS["gcc"], "clang") or string.find(_OPTIONS["gcc"], "pnacl") or string.find(_OPTIONS["gcc"], "asmjs") or string.find(_OPTIONS["gcc"], "android") then
+		if _OPTIONS["clang_version"] == "" then
+			if (version < 40900) then
+				print("GCC version 4.9 or later needed")
+				os.exit(-1)
+			end
+			buildoptions {
+				"-Wno-unused-result", -- needed for fgets,fread on linux
+				-- array bounds checking seems to be buggy in 4.8.1 (try it on video/stvvdp1.c and video/model1.c without -Wno-array-bounds)
+				"-Wno-array-bounds",
+			}
+		else
 			if (version < 30400) then
 				print("Clang version 3.4 or later needed")
 				os.exit(-1)
@@ -963,7 +968,6 @@ end
 				"-Wno-inline-new-delete",
 				"-Wno-constant-logical-operand",
 				"-Wno-deprecated-register",
-				"-fdiagnostics-show-note-include-stack",
 			}
 			if (version >= 30500) then
 				buildoptions {
@@ -977,16 +981,6 @@ end
 					"-Wno-tautological-undefined-compare",
 				}
 			end
-		else
-			if (version < 40900) then
-				print("GCC version 4.9 or later needed")
-				os.exit(-1)
-			end
-				buildoptions {
-					"-Wno-unused-result", -- needed for fgets,fread on linux
-					-- array bounds checking seems to be buggy in 4.8.1 (try it on video/stvvdp1.c and video/model1.c without -Wno-array-bounds)
-					"-Wno-array-bounds",
-				}
 		end
 	end
 
