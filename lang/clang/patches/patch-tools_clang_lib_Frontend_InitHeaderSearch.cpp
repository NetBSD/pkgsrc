$NetBSD: patch-tools_clang_lib_Frontend_InitHeaderSearch.cpp,v 1.2 2013/01/03 15:19:53 adam Exp $

DragonFly no longer has gcc 4.1 in base, so clang stopped working.
We prefer to use gcc 4.7 if available due to a better libstdc++.
The fallback is gcc 4.4 which has been available for several years.

--- tools/clang/lib/Frontend/InitHeaderSearch.cpp.orig	2012-10-24 16:19:39.000000000 +0000
+++ tools/clang/lib/Frontend/InitHeaderSearch.cpp
@@ -24,6 +24,7 @@
 #include "llvm/ADT/Twine.h"
 #include "llvm/Support/raw_ostream.h"
 #include "llvm/Support/ErrorHandling.h"
+#include "llvm/Support/FileSystem.h"
 #include "llvm/Support/Path.h"
 
 #include "clang/Config/config.h" // C_INCLUDE_DIRS
@@ -408,7 +409,10 @@ AddDefaultCPlusPlusIncludePaths(const ll
 #endif
     break;
   case llvm::Triple::DragonFly:
-    AddPath("/usr/include/c++/4.1", CXXSystem, true, false, false);
+    if (llvm::sys::fs::exists("/usr/lib/gcc47"))
+      AddPath("/usr/include/c++/4.7", CXXSystem, true, false, false);
+    else
+      AddPath("/usr/include/c++/4.4", CXXSystem, true, false, false);
     break;
   case llvm::Triple::FreeBSD:
     // FreeBSD 8.0
