$NetBSD: patch-hadrian_src_Rules_BinaryDist.hs,v 1.1 2025/01/29 13:21:53 pho Exp $

Hunk #0, #1, #3:
    Distinguish bootstrapping bindists from regular ones. This is
    pkgsrc-specific.

Hunk #2:
    Do not run `ghc-pkg recache' while creating a binary distribution. We
    don't want a package cache to be installed because we do it in our
    INSTALL script. Also it's not possible to run ghc-pkg in the first
    place without setting LD_LIBRARY_PATH since we don't build relocatable
    executables. This is pkgsrc-specific.

Hunk #4:
    We want our bootkits to be as small as possible, even though `xz -9e'
    is very slow and consumes about 680 MiB of memory. This is
    pkgsrc-specific.

--- hadrian/src/Rules/BinaryDist.hs.orig	2024-05-10 05:05:49.000000000 +0000
+++ hadrian/src/Rules/BinaryDist.hs
@@ -115,7 +115,7 @@ installTo relocatable prefix = do
     root <- buildRoot
     version        <- setting ProjectVersion
     targetPlatform <- setting TargetPlatformFull
-    let ghcVersionPretty = "ghc-" ++ version ++ "-" ++ targetPlatform
+    let ghcVersionPretty = "ghc-" ++ version ++ "-boot-" ++ targetPlatform
         bindistFilesDir  = root -/- "bindist" -/- ghcVersionPretty
     runBuilder (Configure bindistFilesDir) ["--prefix="++prefix] [] []
     let env = case relocatable of
@@ -154,7 +154,7 @@ bindistRules = do
 
         let ghcBuildDir      = root -/- stageString Stage1
             bindistFilesDir  = root -/- "bindist" -/- ghcVersionPretty
-            ghcVersionPretty = "ghc-" ++ version ++ "-" ++ targetPlatform
+            ghcVersionPretty = "ghc-" ++ version ++ "-boot-" ++ targetPlatform
             rtsIncludeDir    = ghcBuildDir -/- "lib" -/- distDir -/- rtsDir
                                -/- "include"
 
@@ -232,17 +232,6 @@ bindistRules = do
         copyDirectory (rtsIncludeDir)         bindistFilesDir
         when windowsHost $ createGhcii (bindistFilesDir -/- "bin")
 
-        -- Call ghc-pkg recache, after copying so the package.cache is
-        -- accurate, then it's on the distributor to use `cp -a` to install
-        -- a relocatable bindist.
-        --
-        -- N.B. the ghc-pkg executable may be prefixed with a target triple
-        -- (c.f. #20267).
-        ghcPkgName <- programName (vanillaContext Stage1 ghcPkg)
-        cmd_ (bindistFilesDir -/- "bin" -/- ghcPkgName) ["recache"]
-
-
-
         -- TODO: we should only embed the docs that have been generated
         -- depending on the current settings (flavours' "ghcDocs" field and
         -- "--docs=.." command-line flag)
@@ -319,7 +308,7 @@ bindistRules = do
             version        <- setting ProjectVersion
             targetPlatform <- setting TargetPlatformFull
 
-            let ghcVersionPretty = "ghc-" ++ version ++ "-" ++ targetPlatform
+            let ghcVersionPretty = "ghc-" ++ version ++ "-boot-" ++ targetPlatform
 
             -- Finally, we create the archive <root>/bindist/ghc-X.Y.Z-platform.tar.xz
             tarPath <- builderPath (Tar Create)
@@ -388,7 +377,7 @@ generateBuildMk = do
 -- | Flag to pass to tar to use the given 'Compressor'.
 compressorTarFlag :: Compressor -> String
 compressorTarFlag Gzip  = "--gzip"
-compressorTarFlag Xz    = "--xz"
+compressorTarFlag Xz    = "--use-compress-program=xz --verbose -9 --extreme"
 compressorTarFlag Bzip2 = "--bzip"
 
 -- | File extension to use for archives compressed with the given 'Compressor'.
