$NetBSD: patch-scripts_genie.lua,v 1.7 2019/11/08 09:44:17 wiz Exp $

Precompilation is broken on NetBSD with gcc-5.3.
Use GNU version of the C++ standard to avoid trouble with alloca on NetBSD.

--- scripts/genie.lua.orig	2019-10-29 17:16:37.000000000 +0000
+++ scripts/genie.lua
@@ -73,11 +73,6 @@ function layoutbuildtask(_folder, _name)
 end
 
 function precompiledheaders()
-	if _OPTIONS["precompile"]==nil or (_OPTIONS["precompile"]~=nil and _OPTIONS["precompile"]=="1") then
-		configuration { "not xcode4" }
-			pchheader("emu.h")
-		configuration { }
-	end
 end
 
 function precompiledheaders_novs()
