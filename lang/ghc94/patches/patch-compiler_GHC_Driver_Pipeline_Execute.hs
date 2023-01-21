$NetBSD: patch-compiler_GHC_Driver_Pipeline_Execute.hs,v 1.1 2023/01/21 04:49:25 pho Exp $

This is pkgsrc-specific. Do not use -Xpreprocessor to pass options to
CPP. Our tool wrappers may remove some of them, and if that happens an
unpaired -Xpreprocessor will be left behind and confuses CC.

--- compiler/GHC/Driver/Pipeline/Execute.hs.orig	2022-12-23 16:19:02.000000000 +0000
+++ compiler/GHC/Driver/Pipeline/Execute.hs
@@ -373,7 +373,7 @@ runCcPhase cc_phase pipe_env hsc_env inp
       aug_imports = augmentImports dflags opts
 
       more_preprocessor_opts = concat
-        [ ["-Xpreprocessor", i]
+        [ [ i ]
         | not hcc
         , i <- aug_imports
         ]
