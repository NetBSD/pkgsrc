$NetBSD: patch-lib_llvmopencl_WorkitemHandler.cc,v 1.1 2025/05/09 06:05:19 adam Exp $

Support LLVM 19.

--- lib/llvmopencl/WorkitemHandler.cc.orig	2024-06-18 12:15:45.000000000 +0000
+++ lib/llvmopencl/WorkitemHandler.cc
@@ -179,7 +179,7 @@ bool WorkitemHandler::fixUndominatedVari
               StringRef baseName;
               std::pair< StringRef, StringRef > pieces = 
                 operand->getName().rsplit('.');
-              if (pieces.second.startswith("pocl_"))
+              if (pieces.second.starts_with("pocl_"))
                 baseName = pieces.first;
               else
                 baseName = operand->getName();
