$NetBSD: patch-hadrian_src_Builder.hs,v 1.2 2026/11/13 14:26:06 pho Exp $

This is pkgsrc-specific. We build haddock as a dynamically-linked
executable but it doesn't contain an rpath to our not-yet-installed shared
libraries. This is usually not a problem because Hadrian embeds relative
rpaths (i.e. $ORIGIN) in dynamically-linked objects but we patch Hadrian
not to do that.

--- hadrian/src/Builder.hs.orig	2025-09-10 16:02:37.000000000 +0000
+++ hadrian/src/Builder.hs
@@ -29,6 +29,7 @@ import Hadrian.Utilities
 import Oracles.Setting (bashPath, targetStage)
 import System.Exit
 import System.IO (stderr)
+import System.Directory (makeAbsolute)
 
 import Base
 import Context
@@ -351,6 +352,10 @@ instance H.Builder Builder where
 
                 Haddock BuildPackage -> runHaddock path buildArgs buildInputs
 
+                Haddock _ -> do
+                  envs <- haddockEnvs
+                  cmd' envs [path] buildArgs
+
                 HsCpp    -> captureStdout
 
                 Make dir -> cmd' buildOptions path ["-C", dir] buildArgs
@@ -383,6 +388,13 @@ instance H.Builder Builder where
 
                 _  -> cmd' [path] buildArgs buildOptions
 
+haddockEnvs :: Action [CmdOption]
+haddockEnvs = do
+    distDynDir' <- distDynDir (vanillaContext Stage1 haddock)
+    shlibPath <- liftIO $ makeAbsolute distDynDir'
+    return [ AddEnv "LD_LIBRARY_PATH" shlibPath
+           , AddEnv "DYLD_LIBRARY_PATH" shlibPath ] -- Darwin
+
 -- | Invoke @haddock@ given a path to it and a list of arguments. The arguments
 -- are passed in a response file.
 runHaddock :: FilePath    -- ^ path to @haddock@
@@ -391,7 +403,8 @@ runHaddock :: FilePath    -- ^ path to @
       -> Action ()
 runHaddock haddockPath flagArgs fileInputs = withTempFile $ \tmp -> do
     writeFile' tmp $ escapeArgs fileInputs
-    cmd [haddockPath] flagArgs ('@' : tmp)
+    envs <- haddockEnvs
+    cmd' envs [haddockPath] flagArgs ('@' : tmp)
 
 -- TODO: Some builders are required only on certain platforms. For example,
 -- 'Objdump' is only required on OpenBSD and AIX. Add support for platform
