$NetBSD: patch-src_llvm-project_llvm_utils_FileCheck_FileCheck.cpp,v 1.3 2021/04/19 17:08:09 he Exp $

Avoid ambiguous function call.

--- src/llvm-project/llvm/utils/FileCheck/FileCheck.cpp.orig	2020-12-08 20:04:43.000000000 +0000
+++ src/llvm-project/llvm/utils/FileCheck/FileCheck.cpp
@@ -558,7 +558,7 @@ static void DumpAnnotatedInput(raw_ostre
   unsigned LineCount = InputFileText.count('\n');
   if (InputFileEnd[-1] != '\n')
     ++LineCount;
-  unsigned LineNoWidth = std::log10(LineCount) + 1;
+  unsigned LineNoWidth = std::log10((float)LineCount) + 1;
   // +3 below adds spaces (1) to the left of the (right-aligned) line numbers
   // on input lines and (2) to the right of the (left-aligned) labels on
   // annotation lines so that input lines and annotation lines are more
