$NetBSD: patch-utils_FileCheck_FileCheck.cpp,v 1.1 2019/06/04 10:22:17 jperkin Exp $

Avoid ambiguous function call.

--- utils/FileCheck/FileCheck.cpp.orig	2019-02-12 15:22:48.000000000 +0000
+++ utils/FileCheck/FileCheck.cpp
@@ -403,7 +403,7 @@ static void DumpAnnotatedInput(raw_ostre
   unsigned LineCount = InputFileText.count('\n');
   if (InputFileEnd[-1] != '\n')
     ++LineCount;
-  unsigned LineNoWidth = log10(LineCount) + 1;
+  unsigned LineNoWidth = log10((double)LineCount) + 1;
   // +3 below adds spaces (1) to the left of the (right-aligned) line numbers
   // on input lines and (2) to the right of the (left-aligned) labels on
   // annotation lines so that input lines and annotation lines are more
