$NetBSD: patch-hadrian_src_Hadrian_Haskell_Cabal_Parse.hs,v 1.2 2026/11/13 14:26:06 pho Exp $

Paper over an upstream bug with respect to parallel build:
https://gitlab.haskell.org/ghc/ghc/-/issues/24436

--- hadrian/src/Hadrian/Haskell/Cabal/Parse.hs.orig	2025-09-10 16:02:37.000000000 +0000
+++ hadrian/src/Hadrian/Haskell/Cabal/Parse.hs
@@ -158,10 +158,10 @@ configurePackage context@Context {..} = 
     -- Normally we will depend on Inplace package databases which enables
     -- cross-package parallelism, but see #24436 for why we lineariese the build
     -- of base and ghc-internal.
-    let forceBaseAfterGhcInternal dep =
-           if dep == ghcInternal && package == base
-              then Final
-              else iplace
+    let forceBaseAfterGhcInternal dep
+            | dep == ghcInternal && package == base        = Final
+            | dep == ghcPrim     && package == ghcInternal = Final
+            | otherwise                                    = iplace
 
 
 
