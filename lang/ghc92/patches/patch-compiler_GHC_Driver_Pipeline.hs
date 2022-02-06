$NetBSD: patch-compiler_GHC_Driver_Pipeline.hs,v 1.1 2022/02/06 05:36:16 pho Exp $

Do not use -Xpreprocessor to pass options to CPP. Our tool wrappers
may remove some of them, and if that happens an unpaired
-Xpreprocessor will be left behind and confuses CC.

--- compiler/GHC/Driver/Pipeline.hs.orig	2021-05-01 06:52:42.897138372 +0000
+++ compiler/GHC/Driver/Pipeline.hs
@@ -1293,8 +1293,8 @@ runPhase (RealPhase cc_phase) input_fn d
         -- (#16737). Doing it in this way is simpler and also enable the C
         -- compiler to perform preprocessing and parsing in a single pass,
         -- but it may introduce inconsistency if a different pgm_P is specified.
-        let more_preprocessor_opts = concat
-              [ ["-Xpreprocessor", i]
+        let more_preprocessor_opts =
+              [ i
               | not hcc
               , i <- getOpts dflags opt_P
               ]
