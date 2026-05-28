$NetBSD: patch-src_qdoc_qdoc_src_qdoc_clangcodeparser.cpp,v 1.1 2026/05/28 07:01:21 adam Exp $

Support LLVM 22.

--- src/qdoc/qdoc/src/qdoc/clangcodeparser.cpp.orig	2026-05-28 06:56:48.576759717 +0000
+++ src/qdoc/qdoc/src/qdoc/clangcodeparser.cpp
@@ -42,7 +42,11 @@
 #include <clang/Lex/Lexer.h>
 #include <llvm/Support/Casting.h>
 
+#if LIBCLANG_VERSION_MAJOR >= 22
+#include <clang/AST/QualTypeNames.h>
+#else
 #include "clang/AST/QualTypeNames.h"
+#endif
 #include "template_declaration.h"
 
 #include <cstdio>
