$NetBSD: patch-src_Development_IDE_GHC_CPP.hs,v 1.1 2026/11/09 13:49:19 pho Exp $

Fix a build failure on GHC 9.10.3. The change to the type Pipeline.CppOpts
was backported to the 9.10 branch, which made this #if conditional
incorrect.

While this is technically an upstream bug, we will be upgrading our GHC in
the near future anyway, so the patch isn't really worth upstreaming.

--- src/Development/IDE/GHC/CPP.hs.orig	2026-11-09 13:40:21.653372462 +0000
+++ src/Development/IDE/GHC/CPP.hs
@@ -34,7 +34,7 @@ import qualified GHC.Driver.Pipeline.Exe
 import qualified GHC.SysTools.Cpp                as Pipeline
 #endif
 
-#if MIN_VERSION_ghc(9,11,0)
+#if MIN_VERSION_ghc(9,10,3)
 import qualified GHC.SysTools.Tasks              as Pipeline
 #endif
 
@@ -56,7 +56,7 @@ doCpp env input_fn output_fn =
 #if MIN_VERSION_ghc(9,5,0)
     let cpp_opts = Pipeline.CppOpts
                  { cppLinePragmas = True
-#if MIN_VERSION_ghc(9,11,0)
+#if MIN_VERSION_ghc(9,10,3)
                  , sourceCodePreprocessor = Pipeline.SCPHsCpp
 #elif MIN_VERSION_ghc(9,10,0)
                  , useHsCpp = True
