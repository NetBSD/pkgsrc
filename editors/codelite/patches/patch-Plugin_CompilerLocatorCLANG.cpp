$NetBSD: patch-Plugin_CompilerLocatorCLANG.cpp,v 1.1 2024/02/05 14:32:25 nros Exp $

Codelite generates gmake Makefiles, so use pkgsrc gmake to make
them build correctly

--- Plugin/CompilerLocatorCLANG.cpp.orig	2023-01-11 21:18:07.000000000 +0000
+++ Plugin/CompilerLocatorCLANG.cpp
@@ -220,7 +220,7 @@ void CompilerLocatorCLANG::AddTools(Comp
         AddTool(compiler, "MAKE", "mingw32-make.exe", makeExtraArgs);
     }
 #else
-    AddTool(compiler, "MAKE", "make", makeExtraArgs);
+    AddTool(compiler, "MAKE", "gmake", makeExtraArgs);
 #endif
 }
 
