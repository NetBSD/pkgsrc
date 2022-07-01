$NetBSD: patch-scripts_genie.lua,v 1.9 2022/07/01 16:57:29 wiz Exp $

Some libraries have circular dependencies - explicitly allow this on NetBSD.
https://github.com/mamedev/mame/issues/10011

--- scripts/genie.lua.orig	2022-06-29 16:31:53.000000000 +0000
+++ scripts/genie.lua
@@ -1253,6 +1253,10 @@ configuration { "linux-*" }
 		end
 
 
+configuration { "netbsd" }
+		flags {
+			"LinkSupportCircularDependencies",
+		}
 
 configuration { "osx*" }
 		links {
