$NetBSD: patch-hadrian_src_Settings_Packages.hs,v 1.1 2025/01/29 13:21:53 pho Exp $

Hunk #0, #2:
  Don't assume we always build the threaded RTS. We can't upstream this
  until they adopt this change to Haddock:
  https://github.com/haskell/haddock/commit/75a94e010fb5b0236c670d22b04f5472397dc15d

Hunk #1:
  Remove tool dependency on alex from Cabal-syntax. We can only upstream
  this after patch-libraries_Cabal_Cabal-syntax_Cabal-syntax.cabal is
  merged, and the upstream of GHC adopts the change.

--- hadrian/src/Settings/Packages.hs.orig	2024-05-10 05:05:49.000000000 +0000
+++ hadrian/src/Settings/Packages.hs
@@ -34,6 +34,7 @@ packageArgs = do
     cursesLibraryDir <- getSetting CursesLibDir
     ffiIncludeDir  <- getSetting FfiIncludeDir
     ffiLibraryDir  <- getSetting FfiLibDir
+    rtsWays          <- getRtsWays
     stageVersion <- readVersion <$> (expr $ ghcVersionStage stage)
 
     mconcat
@@ -52,6 +53,11 @@ packageArgs = do
         , package cabal ?
           stage0 ? builder Ghc ? arg "-O0"
 
+        ------------------------------ cabalSyntax -----------------------------
+        , package cabalSyntax ?
+          builder (Cabal Flags) ?
+          arg "-build-tool-depends"
+
         ------------------------------- compiler -------------------------------
         , package compiler ? mconcat
           [ builder Alex ? arg "--latin1"
@@ -176,7 +182,17 @@ packageArgs = do
 
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
