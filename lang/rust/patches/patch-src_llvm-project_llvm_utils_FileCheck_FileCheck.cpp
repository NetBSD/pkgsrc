$NetBSD: patch-src_llvm-project_llvm_utils_FileCheck_FileCheck.cpp,v 1.7 2022/01/21 23:20:36 he Exp $

Avoid ambiguous function call.

--- src/llvm-project/llvm/utils/FileCheck/FileCheck.cpp.orig	2019-02-12 15:22:48.000000000 +0000
+++ src/llvm-project/llvm/utils/FileCheck/FileCheck.cpp
@@ -592,7 +592,7 @@ static void DumpAnnotatedInput(raw_ostre
   unsigned LineCount = InputFileText.count('\n');
   if (InputFileEnd[-1] != '\n')
     ++LineCount;
-  unsigned LineNoWidth = std::log10(LineCount) + 1;
+  unsigned LineNoWidth = std::log10((float)LineCount) + 1;
   // +3 below adds spaces (1) to the left of the (right-aligned) line numbers
   // on input lines and (2) to the right of the (left-aligned) labels on
   // annotation lines so that input lines and annotation lines are more
