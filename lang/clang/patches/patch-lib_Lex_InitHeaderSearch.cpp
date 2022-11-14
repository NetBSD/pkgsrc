$NetBSD: patch-lib_Lex_InitHeaderSearch.cpp,v 1.2 2022/11/14 18:44:05 adam Exp $

Don't add /usr/local/include by default on Solaris.
was: patch-lib_Frontend_InitHeaderSearch.cpp

--- lib/Lex/InitHeaderSearch.cpp.orig	2022-11-02 03:11:40.000000000 +0000
+++ lib/Lex/InitHeaderSearch.cpp
@@ -242,6 +242,7 @@ void InitHeaderSearch::AddDefaultCInclud
     case llvm::Triple::PS5:
     case llvm::Triple::ELFIAMCU:
     case llvm::Triple::Fuchsia:
+    case llvm::Triple::Solaris:
       break;
     case llvm::Triple::Win32:
       if (triple.getEnvironment() != llvm::Triple::Cygnus)
