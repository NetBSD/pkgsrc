$NetBSD: patch-scripts_genie.lua,v 1.1 2016/04/04 17:32:17 joerg Exp $

Detect clang correctly.
Use GNU version of the C++ standard to avoid trouble with alloca on NetBSD.

--- scripts/genie.lua.orig	2016-04-04 07:47:22.946297308 +0000
+++ scripts/genie.lua
@@ -692,12 +692,12 @@ local version = str_to_version(_OPTIONS[
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
 	if _OPTIONS["targetos"]=="os2" then
@@ -708,13 +708,13 @@ else
 	else
 		buildoptions_cpp {
 			"-x c++",
-			"-std=c++14",
+			"-std=gnu++14",
 		}
 	end
 
 	buildoptions_objc {
 		"-x objective-c++",
-		"-std=c++14",
+		"-std=gnu++14",
 	}
 end
 -- this speeds it up a bit by piping between the preprocessor/compiler/assembler
@@ -955,7 +955,17 @@ end
 
 
 		local version = str_to_version(_OPTIONS["gcc_version"])
-		if string.find(_OPTIONS["gcc"], "clang") then
+		if _OPTIONS["clang_version"] == "" then
+			if (version < 40900) then
+				print("GCC version 4.9 or later needed")
+				os.exit(-1)
+			end
+				buildoptions {
+					"-Wno-unused-result", -- needed for fgets,fread on linux
+					-- array bounds checking seems to be buggy in 4.8.1 (try it on video/stvvdp1.c and video/model1.c without -Wno-array-bounds)
+					"-Wno-array-bounds",
+				}
+		else
 			if (version < 30400) then
 				print("Clang version 3.4 or later needed")
 				os.exit(-1)
@@ -981,16 +991,6 @@ end
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
 	
