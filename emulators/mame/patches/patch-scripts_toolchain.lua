$NetBSD: patch-scripts_toolchain.lua,v 1.4 2018/12/08 23:18:54 wiz Exp $

Allow Clang on FreeBSD, NetBSD, and OpenBSD.
https://github.com/mamedev/mame/pull/4383

--- scripts/toolchain.lua.orig	2018-09-26 04:43:31.000000000 +0000
+++ scripts/toolchain.lua
@@ -23,6 +23,7 @@ newoption {
 		{ "android-x64",   "Android - x64"          },
 		{ "asmjs",         "Emscripten/asm.js"      },
 		{ "freebsd",       "FreeBSD"                },
+		{ "freebsd-clang", "FreeBSD (clang compiler)"},
 		{ "linux-gcc",     "Linux (GCC compiler)"   },
 		{ "linux-clang",   "Linux (Clang compiler)" },
 		{ "ios-arm",       "iOS - ARM"              },
@@ -31,7 +32,9 @@ newoption {
 		{ "mingw64-gcc",   "MinGW64"                },
 		{ "mingw-clang",   "MinGW (clang compiler)" },
 		{ "netbsd",        "NetBSD"                },
+		{ "netbsd-clang",  "NetBSD (clang compiler)"},
 		{ "openbsd",       "OpenBSD"                },
+		{ "openbsd-clang", "OpenBSD (clang compiler)"},
 		{ "osx",           "OSX (GCC compiler)"     },
 		{ "osx-clang",     "OSX (Clang compiler)"   },
 		{ "pnacl",         "Native Client - PNaCl"  },
@@ -168,14 +171,26 @@ function toolchain(_buildDir, _subDir)
 			location (_buildDir .. "projects/" .. _subDir .. "/".. _ACTION .. "-freebsd")
 		end
 
+		if "freebsd-clang" == _OPTIONS["gcc"] then
+			location (_buildDir .. "projects/" .. _subDir .. "/".. _ACTION .. "-freebsd-clang")
+		end
+
 		if "netbsd" == _OPTIONS["gcc"] then
 			location (_buildDir .. "projects/" .. _subDir .. "/".. _ACTION .. "-netbsd")
 		end
 
+		if "netbsd-clang" == _OPTIONS["gcc"] then
+			location (_buildDir .. "projects/" .. _subDir .. "/".. _ACTION .. "-netbsd-clang")
+		end
+
 		if "openbsd" == _OPTIONS["gcc"] then
 			location (_buildDir .. "projects/" .. _subDir .. "/".. _ACTION .. "-openbsd")
 		end
 
+		if "openbsd-clang" == _OPTIONS["gcc"] then
+			location (_buildDir .. "projects/" .. _subDir .. "/".. _ACTION .. "-openbsd-clang")
+		end
+
 		if "ios-arm" == _OPTIONS["gcc"] then
 			premake.gcc.cc  = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
 			premake.gcc.cxx = "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++"
