$NetBSD: patch-hadrian_src_Settings_Packages.hs,v 1.2 2024/05/12 02:52:35 pho Exp $

Hunk #0, #1:
  Don't assume we always build the threaded RTS. We can't upstream this
  until they adopt this change to Haddock:
  https://github.com/haskell/haddock/commit/75a94e010fb5b0236c670d22b04f5472397dc15d

Hunk #2:
  Hadrian does something unholy on i386 to gain speed but it seems to be
  incompatible with LLD. Disable the speed hack to work around a linkage
  failure. Ideally we should do this by detecting the type of linker but
  not the OS. (Don't upstream this as-is. Do detect the linker type.)

--- hadrian/src/Settings/Packages.hs.orig	2024-02-22 20:59:45.000000000 +0000
+++ hadrian/src/Settings/Packages.hs
@@ -29,6 +29,7 @@ packageArgs = do
     cursesLibraryDir <- getSetting CursesLibDir
     ffiIncludeDir  <- getSetting FfiIncludeDir
     ffiLibraryDir  <- getSetting FfiLibDir
+    rtsWays          <- getRtsWays
 
     mconcat
         --------------------------------- base ---------------------------------
@@ -166,7 +167,17 @@ packageArgs = do
 
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
@@ -441,7 +452,7 @@ rtsPackageArgs = package rts ? do
 speedHack :: Action Bool
 speedHack = do
     i386   <- anyTargetArch ["i386"]
-    goodOS <- not <$> anyTargetOs ["darwin", "solaris2"]
+    goodOS <- not <$> anyTargetOs ["darwin", "solaris2", "freebsd"]
     return $ i386 && goodOS
 
 -- See @rts/ghc.mk@.
