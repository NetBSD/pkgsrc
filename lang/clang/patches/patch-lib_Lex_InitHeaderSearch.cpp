$NetBSD: patch-lib_Lex_InitHeaderSearch.cpp,v 1.3 2023/10/06 19:15:20 adam Exp $

Don't add /usr/local/include by default on Solaris.
was: patch-lib_Frontend_InitHeaderSearch.cpp

--- lib/Lex/InitHeaderSearch.cpp.orig	2023-04-05 05:36:38.000000000 +0200
+++ lib/Lex/InitHeaderSearch.cpp	2023-04-28 23:52:32.313523683 +0200
@@ -236,6 +236,7 @@
     case llvm::Triple::PS4:
     case llvm::Triple::PS5:
     case llvm::Triple::ELFIAMCU:
+    case llvm::Triple::Solaris:
       break;
     case llvm::Triple::Win32:
       if (triple.getEnvironment() != llvm::Triple::Cygnus)
