$NetBSD: patch-lib_Lex_InitHeaderSearch.cpp,v 1.1 2022/08/13 09:58:04 tnn Exp $

Don't add /usr/local/include by default on Solaris.
was: patch-lib_Frontend_InitHeaderSearch.cpp

--- lib/Lex/InitHeaderSearch.cpp.orig	2022-06-22 16:46:24.000000000 +0000
+++ lib/Lex/InitHeaderSearch.cpp
@@ -241,6 +241,7 @@ void InitHeaderSearch::AddDefaultCInclud
     case llvm::Triple::PS4:
     case llvm::Triple::ELFIAMCU:
     case llvm::Triple::Fuchsia:
+    case llvm::Triple::Solaris:
       break;
     case llvm::Triple::Win32:
       if (triple.getEnvironment() != llvm::Triple::Cygnus)
