$NetBSD: patch-lib_Frontend_InitHeaderSearch.cpp,v 1.2 2018/12/09 20:04:38 adam Exp $

Don't add /usr/local/include by default on Solaris.

--- lib/Frontend/InitHeaderSearch.cpp.orig	2018-06-28 23:23:45.000000000 +0000
+++ lib/Frontend/InitHeaderSearch.cpp
@@ -221,6 +221,7 @@ void InitHeaderSearch::AddDefaultCInclud
     case llvm::Triple::PS4:
     case llvm::Triple::ELFIAMCU:
     case llvm::Triple::Fuchsia:
+    case llvm::Triple::Solaris:
       break;
     case llvm::Triple::Win32:
       if (triple.getEnvironment() != llvm::Triple::Cygnus)
