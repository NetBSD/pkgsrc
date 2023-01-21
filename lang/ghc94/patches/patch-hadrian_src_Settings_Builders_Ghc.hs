$NetBSD: patch-hadrian_src_Settings_Builders_Ghc.hs,v 1.1 2023/01/21 04:49:25 pho Exp $

Don't use rpaths relative to $ORIGIN. Use the final installation path. This
is pkgsrc-specific.

--- hadrian/src/Settings/Builders/Ghc.hs.orig	2022-12-23 16:19:02.000000000 +0000
+++ hadrian/src/Settings/Builders/Ghc.hs
@@ -5,6 +5,7 @@ module Settings.Builders.Ghc (ghcBuilder
 import Hadrian.Haskell.Cabal
 import Hadrian.Haskell.Cabal.Type
 
+import CommandLine
 import Flavour
 import Packages
 import Settings.Builders.Common
@@ -104,10 +105,10 @@ ghcLinkArgs = builder (Ghc LinkHs) ? do
     fmwks   <- getContextData frameworks
     way     <- getWay
 
-    -- Relative path from the output (rpath $ORIGIN).
-    originPath <- dropFileName <$> getOutput
-    context <- getContext
-    libPath' <- expr (libPath context)
+    -- Absolute rpath to the final destination.
+    fileName <- takeFileName <$> getOutput
+    prefix   <- fromMaybe (error "--prefix missing from the command line") <$> expr cmdPrefix
+    projVer  <- getSetting ProjectVersion
     st <- getStage
     distDir <- expr (Context.distDir st)
 
@@ -121,17 +122,8 @@ ghcLinkArgs = builder (Ghc LinkHs) ? do
 
     let
         dynamic = Dynamic `wayUnit` way
-        distPath = libPath' -/- distDir
-        originToLibsDir = makeRelativeNoSysLink originPath distPath
-        rpath
-            -- Programs will end up in the bin dir ($ORIGIN) and will link to
-            -- libraries in the lib dir.
-            | isProgram pkg = metaOrigin -/- originToLibsDir
-            -- libraries will all end up in the lib dir, so just use $ORIGIN
-            | otherwise     = metaOrigin
-            where
-                metaOrigin | osxTarget = "@loader_path"
-                           | otherwise = "$ORIGIN"
+        ghclibdir = prefix -/- "lib" -/- ("ghc-" ++ projVer)
+        rpath     = ghclibdir -/- "lib" -/- distDir
 
         -- TODO: an alternative would be to generalize by linking with extra
         -- bundled libraries, but currently the rts is the only use case. It is
@@ -144,23 +136,13 @@ ghcLinkArgs = builder (Ghc LinkHs) ? do
             , arg ("-l" ++ libffiName')
             ]
 
-        -- This is the -rpath argument that is required for the bindist scenario
-        -- to work. Indeed, when you install a bindist, the actual executables
-        -- end up nested somewhere under $libdir, with the wrapper scripts
-        -- taking their place in $bindir, and 'rpath' therefore doesn't seem
-        -- to give us the right paths for such a case.
-        -- TODO: Could we get away with just one rpath...?
-        bindistRpath = "$ORIGIN" -/- ".." -/- ".." -/- originToLibsDir
-
     mconcat [ dynamic ? mconcat
                 [ arg "-dynamic"
                 -- TODO what about windows?
                 , isLibrary pkg ? pure [ "-shared", "-dynload", "deploy" ]
                 , hostSupportsRPaths ? mconcat
                       [ arg ("-optl-Wl,-rpath," ++ rpath)
-                      , isProgram pkg ? arg ("-optl-Wl,-rpath," ++ bindistRpath)
-                      -- The darwin and Windows linkers don't support/require the -zorigin option
-                      , not (osxTarget || winTarget) ? arg "-optl-Wl,-zorigin"
+                      , isLibrary pkg ? pure ["-dylib-install-name", rpath -/- fileName]
                       -- We set RPATH directly (relative to $ORIGIN). There's
                       -- no reason for GHC to inject further RPATH entries.
                       -- See #19485.
