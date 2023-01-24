$NetBSD: patch-hadrian_src_Settings_Packages.hs,v 1.3 2023/01/24 11:13:18 pho Exp $

Hunk #0-#2:
  Don't assume we always build the threaded RTS. Not upstreamed yet. This can
  be upstreamed only after [1] is merged and GHC pulls it.

  [1]: https://github.com/haskell/haddock/pull/1575

Hunk #3:
  Hadrian does something unholy on i386 to gain speed but it seems to be
  incompatible with LLD. Disable the speed hack to work around a linkage
  failure. Ideally we should do this by detecting the type of linker but
  not the OS.

--- hadrian/src/Settings/Packages.hs.orig	2022-12-23 16:19:02.000000000 +0000
+++ hadrian/src/Settings/Packages.hs
@@ -29,6 +29,7 @@ packageArgs = do
     ffiIncludeDir  <- getSetting FfiIncludeDir
     ffiLibraryDir  <- getSetting FfiLibDir
     debugAssertions  <- ghcDebugAssertions <$> expr flavour
+    rtsWays          <- getRtsWays
 
     mconcat
         --------------------------------- base ---------------------------------
@@ -161,8 +162,18 @@ packageArgs = do
 
         -------------------------------- haddock -------------------------------
         , package haddock ?
-          builder (Cabal Flags) ? arg "in-ghc-tree"
+          builder (Cabal Flags) ? mconcat
+          [ arg "in-ghc-tree"
+          , ifM stage0
+                -- We build a threaded haddock on stage 1 if the
+                -- bootstrapping compiler supports it.
+                (threadedBootstrapper `cabalFlag` "threaded")
 
+                -- We build a threaded haddock on stage N, N>1 if the
+                -- configuration calls for it.
+                (any (wayUnit Threaded) rtsWays `cabalFlag` "threaded")
+          ]
+
         ---------------------------------- text --------------------------------
         , package text ? mconcat
           -- Disable SIMDUTF by default due to packaging difficulties
@@ -387,7 +398,8 @@ rtsPackageArgs = package rts ? do
 
     mconcat
         [ builder (Cabal Flags) ? mconcat
-          [ any (wayUnit Profiling) rtsWays `cabalFlag` "profiling"
+          [ any (wayUnit Threaded) rtsWays  `cabalFlag` "threaded"
+          , any (wayUnit Profiling) rtsWays `cabalFlag` "profiling"
           , any (wayUnit Debug) rtsWays     `cabalFlag` "debug"
           , any (wayUnit Dynamic) rtsWays   `cabalFlag` "dynamic"
           , useSystemFfi                    `cabalFlag` "use-system-libffi"
@@ -444,7 +456,7 @@ rtsPackageArgs = package rts ? do
 speedHack :: Action Bool
 speedHack = do
     i386   <- anyTargetArch ["i386"]
-    goodOS <- not <$> anyTargetOs ["darwin", "solaris2"]
+    goodOS <- not <$> anyTargetOs ["darwin", "solaris2", "freebsd"]
     return $ i386 && goodOS
 
 -- See @rts/ghc.mk@.
