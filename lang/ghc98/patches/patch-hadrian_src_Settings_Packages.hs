$NetBSD: patch-hadrian_src_Settings_Packages.hs,v 1.5 2025/01/27 15:08:08 pho Exp $

Hunk #1, #3:
  Don't assume we always build the threaded RTS. We can't upstream this
  until they adopt this change to Haddock:
  https://github.com/haskell/haddock/commit/75a94e010fb5b0236c670d22b04f5472397dc15d

Hunk #0, #1, #2:
  Fix build with GHC >= 9.8.1:
  https://gitlab.haskell.org/ghc/ghc/-/merge_requests/11541

Hunk #4:
  Hadrian does something unholy on i386 to gain speed but it seems to be
  incompatible with LLD. Disable the speed hack to work around a linkage
  failure. Ideally we should do this by detecting the type of linker but
  not the OS. (Don't upstream this as-is. Do detect the linker type.)

--- hadrian/src/Settings/Packages.hs.orig	2024-02-22 20:59:45.000000000 +0000
+++ hadrian/src/Settings/Packages.hs
@@ -6,6 +6,7 @@ import Oracles.Setting
 import Oracles.Flag
 import Packages
 import Settings
+import Data.Version.Extra
 
 -- | Package-specific command-line arguments.
 packageArgs :: Args
@@ -29,6 +30,8 @@ packageArgs = do
     cursesLibraryDir <- getSetting CursesLibDir
     ffiIncludeDir  <- getSetting FfiIncludeDir
     ffiLibraryDir  <- getSetting FfiLibDir
+    stageVersion     <- readVersion <$> (expr $ ghcVersionStage stage)
+    rtsWays          <- getRtsWays
 
     mconcat
         --------------------------------- base ---------------------------------
@@ -79,7 +82,7 @@ packageArgs = do
             -- not being fixed to `ghc`, when building stage0, we must set
             -- -this-unit-id to `ghc` because the boot compiler expects that.
             -- We do it through a cabal flag in ghc.cabal
-            , stage0 ? arg "+hadrian-stage0"
+            , stageVersion < makeVersion [9, 8, 1] ? arg "+hadrian-stage0"
             , flag StaticLibzstd `cabalFlag` "static-libzstd"
             ]
 
@@ -166,7 +169,17 @@ packageArgs = do
 
         -------------------------------- haddock -------------------------------
         , package haddock ?
-          builder (Cabal Flags) ? arg "in-ghc-tree"
+          builder (Cabal Flags) ? mconcat
+          [ arg "in-ghc-tree"
+          , ifM stage0
+                -- We build a threaded haddock on stage 1 if the
+                -- bootstrapping compiler supports it.
+                (threadedBootstrapper `cabalFlag` "threaded")
+
+                -- We build a threaded haddock on stage N, N>1 if the
+                -- configuration calls for it.
+                (any (wayUnit Threaded) rtsWays `cabalFlag` "threaded")
+          ]
 
         ---------------------------------- text --------------------------------
         , package text ? mconcat
@@ -441,7 +454,7 @@ rtsPackageArgs = package rts ? do
 speedHack :: Action Bool
 speedHack = do
     i386   <- anyTargetArch ["i386"]
-    goodOS <- not <$> anyTargetOs ["darwin", "solaris2"]
+    goodOS <- not <$> anyTargetOs ["darwin", "solaris2", "freebsd"]
     return $ i386 && goodOS
 
 -- See @rts/ghc.mk@.
