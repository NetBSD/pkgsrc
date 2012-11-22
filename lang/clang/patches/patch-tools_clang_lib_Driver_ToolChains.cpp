$NetBSD: patch-tools_clang_lib_Driver_ToolChains.cpp,v 1.1 2012/11/22 22:45:15 marino Exp $

DragonFly no longer has gcc 4.1 in base, so clang stopped working.
We prefer to use gcc 4.7 if available due to a better libstdc++.
The fallback is gcc 4.4 which has been available for several years.

--- tools/clang/lib/Driver/ToolChains.cpp.orig	2012-05-12 00:16:02.000000000 +0000
+++ tools/clang/lib/Driver/ToolChains.cpp
@@ -2307,7 +2307,8 @@ DragonFly::DragonFly(const Driver &D, co
 
   getFilePaths().push_back(getDriver().Dir + "/../lib");
   getFilePaths().push_back("/usr/lib");
-  getFilePaths().push_back("/usr/lib/gcc41");
+  getFilePaths().push_back("/usr/lib/gcc47");
+  getFilePaths().push_back("/usr/lib/gcc44");
 }
 
 Tool &DragonFly::SelectTool(const Compilation &C, const JobAction &JA,
