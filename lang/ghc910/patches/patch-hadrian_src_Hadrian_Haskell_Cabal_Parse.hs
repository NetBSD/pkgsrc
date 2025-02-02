$NetBSD: patch-hadrian_src_Hadrian_Haskell_Cabal_Parse.hs,v 1.1 2025/02/02 16:21:31 pho Exp $

Paper over an upstream bug with respect to parallel build:
https://gitlab.haskell.org/ghc/ghc/-/issues/24436

--- hadrian/src/Hadrian/Haskell/Cabal/Parse.hs.orig	2025-02-02 16:01:35.734838907 +0000
+++ hadrian/src/Hadrian/Haskell/Cabal/Parse.hs
@@ -71,6 +71,7 @@ import System.Directory (getCurrentDirec
 import qualified Distribution.InstalledPackageInfo as CP
 import Distribution.Simple.Utils (writeUTF8File)
 import Utilities
+import Packages
 
 
 -- | Parse the Cabal file of a given 'Package'. This operation is cached by the
@@ -150,8 +151,12 @@ configurePackage context@Context {..} = 
 
     -- Stage packages are those we have in this stage.
     stagePkgs <- stagePackages stage
+    let maybeLinearise dep
+          | dep == ghcInternal && package == base        = Final
+          | dep == ghcPrim     && package == ghcInternal = Final
+          | otherwise                                    = iplace
     -- We'll need those packages in our package database.
-    deps <- sequence [ pkgConfFile (context { package = pkg })
+    deps <- sequence [ pkgConfFile (context { package = pkg, iplace = maybeLinearise pkg })
                      | pkg <- depPkgs, pkg `elem` stagePkgs ]
     need $ extraPreConfigureDeps ++ deps
 
