$NetBSD: patch-scripts_src_3rdparty.lua,v 1.3 2016/03/04 12:47:13 wiz Exp $

--- scripts/src/3rdparty.lua.orig	2016-02-24 07:02:17.000000000 +0000
+++ scripts/src/3rdparty.lua
@@ -1153,6 +1153,15 @@ project "uv"
 			MAME_DIR .. "3rdparty/libuv/src/unix/kqueue.c",
 		}
 	end
+	if _OPTIONS["targetos"]=="netbsd" then
+		files {
+			MAME_DIR .. "3rdparty/libuv/src/unix/netbsd.c",
+			MAME_DIR .. "3rdparty/libuv/src/unix/kqueue.c",
+		}
+		links {
+			"kvm",
+		}
+	end
 
 	if (_OPTIONS["SHADOW_CHECK"]=="1") then
 		removebuildoptions {
