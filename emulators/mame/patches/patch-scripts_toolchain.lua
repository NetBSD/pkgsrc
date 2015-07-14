$NetBSD: patch-scripts_toolchain.lua,v 1.1 2015/07/14 20:14:49 wiz Exp $

Add NetBSD support.

--- scripts/toolchain.lua.orig	2015-06-24 09:53:32.000000000 +0000
+++ scripts/toolchain.lua
@@ -24,6 +24,7 @@ newoption {
 		{ "mingw-clang",   "MinGW (clang compiler)" },
 		{ "nacl",          "Native Client"          },
 		{ "nacl-arm",      "Native Client - ARM"    },
+		{ "netbsd",        "NetBSD"                },
 		{ "osx",           "OSX (GCC compiler)"     },
 		{ "osx-clang",     "OSX (Clang compiler)"   },
 		{ "pnacl",         "Native Client - PNaCl"  },
@@ -147,6 +148,10 @@ function toolchain(_buildDir, _subDir)
 			location (_buildDir .. "projects/" .. _subDir .. "/".. _ACTION .. "-freebsd")
 		end
 
+		if "netbsd" == _OPTIONS["gcc"] then
+			location (_buildDir .. "projects/" .. _subDir .. "/".. _ACTION .. "-netbsd")
+		end
+
 		if "ios-arm" == _OPTIONS["gcc"] then
 			premake.gcc.cc  = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
 			premake.gcc.cxx = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++"
@@ -590,7 +595,30 @@ function toolchain(_buildDir, _subDir)
 	
 	configuration { "freebsd", "x64", "Debug" }
 		targetdir (_buildDir .. "freebsd" .. "/bin/x64/Debug")
+
+	configuration { "netbsd", "x32" }
+		objdir (_buildDir .. "netbsd" .. "/obj")
+		buildoptions {
+			"-m32",
+		}
 		
+	configuration { "netbsd", "x32", "Release" }
+		targetdir (_buildDir .. "netbsd" .. "/bin/x32/Release")
+	
+	configuration { "netbsd", "x32", "Debug" }
+		targetdir (_buildDir .. "netbsd" .. "/bin/x32/Debug")
+
+	configuration { "netbsd", "x64" }
+		objdir (_buildDir .. "netbsd" .. "/obj")
+		buildoptions {
+			"-m64",
+		}
+	configuration { "netbsd", "x64", "Release" }
+		targetdir (_buildDir .. "netbsd" .. "/bin/x64/Release")
+	
+	configuration { "netbsd", "x64", "Debug" }
+		targetdir (_buildDir .. "netbsd" .. "/bin/x64/Debug")
+
 	configuration { "android-*" }
 		includedirs {
 			"$(ANDROID_NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.8/include",
