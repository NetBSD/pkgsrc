$NetBSD: patch-Source_cmForEachCommand.cxx,v 1.1 2025/08/22 10:17:17 wiz Exp $

https://gitlab.kitware.com/cmake/cmake/-/commit/37e27f71bc356d880c908040cd0cb68fa2c371b8

--- Source/cmForEachCommand.cxx.orig	2025-08-05 14:55:57.000000000 +0000
+++ Source/cmForEachCommand.cxx
@@ -100,6 +100,9 @@ bool cmForEachFunctionBlocker::Arguments
 bool cmForEachFunctionBlocker::Replay(
   std::vector<cmListFileFunction> functions, cmExecutionStatus& inStatus)
 {
+  if (this->Args.size() == this->IterationVarsCount) {
+    return true;
+  }
   return this->ZipLists ? this->ReplayZipLists(functions, inStatus)
                         : this->ReplayItems(functions, inStatus);
 }
