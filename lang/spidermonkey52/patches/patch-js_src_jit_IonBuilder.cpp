$NetBSD: patch-js_src_jit_IonBuilder.cpp,v 1.1 2019/07/09 16:08:38 maya Exp $

# HG changeset patch
# User Jan de Mooij <jdemooij@mozilla.com>
# Date 1556819484 0
# Node ID dbd28ea2e13c17d9566a8a95370b87a6d3341e71
# Parent  76d84e7aeb3ffc34d0d52cc4adc89bd6ddd0c2e7
Bug 1544792 - Abort on try-catch blocks when doing definite properties analysis. r=nbp, a=pascalc

Ion does not compile the catch block so the analysis fails to account for code
there.

Differential Revision: https://phabricator.services.mozilla.com/D29475

--- js/src/jit/IonBuilder.cpp.orig	2018-04-28 01:04:03.000000000 +0000
+++ js/src/jit/IonBuilder.cpp
@@ -4540,6 +4540,10 @@ IonBuilder::jsop_try()
     // accessing the arguments within the 'catch' block is not accounted for.
     if (info().analysisMode() == Analysis_ArgumentsUsage)
         return abort("Try-catch during arguments usage analysis");
+    // Try-catch during analyses is not yet supported. Code within the 'catch'
+    // block is not accounted for.
+    if (info().isAnalysis())
+        return abort("Try-catch during analysis");
 
     graph().setHasTryBlock();
 
