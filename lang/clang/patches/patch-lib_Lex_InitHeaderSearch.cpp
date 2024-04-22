$NetBSD: patch-lib_Lex_InitHeaderSearch.cpp,v 1.4 2024/04/22 07:03:35 adam Exp $

Don't add /usr/local/include by default on Solaris.
was: patch-lib_Frontend_InitHeaderSearch.cpp

--- lib/Lex/InitHeaderSearch.cpp.orig	2023-10-03 06:37:35.000000000 +0000
+++ lib/Lex/InitHeaderSearch.cpp
@@ -234,6 +234,7 @@ void InitHeaderSearch::AddDefaultCInclud
     case llvm::Triple::CloudABI:
     case llvm::Triple::NaCl:
     case llvm::Triple::ELFIAMCU:
+    case llvm::Triple::Solaris:
       break;
     case llvm::Triple::Win32:
       if (triple.getEnvironment() != llvm::Triple::Cygnus)
