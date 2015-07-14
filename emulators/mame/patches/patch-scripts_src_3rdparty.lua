$NetBSD: patch-scripts_src_3rdparty.lua,v 1.1 2015/07/14 20:14:49 wiz Exp $

Add NetBSD "support" for portmidi.

--- scripts/src/3rdparty.lua.orig	2015-06-24 09:53:30.000000000 +0000
+++ scripts/src/3rdparty.lua
@@ -534,6 +534,13 @@ project "portmidi"
 			MAME_DIR .. "3rdparty/portmidi/porttime/ptlinux.c",
 		}
 	end
+	if _OPTIONS["targetos"]=="netbsd" then
+		files {
+			MAME_DIR .. "3rdparty/portmidi/pm_linux/pmlinux.c",
+			MAME_DIR .. "3rdparty/portmidi/pm_linux/finddefault.c",
+			MAME_DIR .. "3rdparty/portmidi/porttime/ptlinux.c",
+		}
+	end
 	if _OPTIONS["targetos"]=="macosx" then
 		files {
 			MAME_DIR .. "3rdparty/portmidi/pm_mac/pmmac.c",
@@ -591,6 +598,11 @@ project "bgfx"
 			MAME_DIR .. "3rdparty/bx/include/compat/freebsd",
 		}
 
+	configuration { "netbsd" }
+		includedirs {
+			MAME_DIR .. "3rdparty/bx/include/compat/freebsd",
+		}
+
 	configuration { "gmake" }
 		buildoptions {		
 			"-Wno-uninitialized",
