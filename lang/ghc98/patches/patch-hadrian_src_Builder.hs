$NetBSD: patch-hadrian_src_Builder.hs,v 1.1 2024/04/28 05:58:58 pho Exp $

This is pkgsrc-specific. We build haddock as a dynamically-linked
executable but it doesn't contain an rpath to our not-yet-installed shared
libraries. This is usually not a problem because Hadrian embeds relative
rpaths (i.e. $ORIGIN) in dynamically-linked objects but we patch Hadrian
not to do that.

--- hadrian/src/Builder.hs.orig	2024-02-22 20:59:45.000000000 +0000
+++ hadrian/src/Builder.hs
@@ -31,6 +31,7 @@ import Hadrian.Utilities
 import Oracles.Setting (bashPath)
 import System.Exit
 import System.IO (stderr)
+import System.Directory (makeAbsolute)
 
 import Base
 import Context
@@ -386,8 +387,20 @@ instance H.Builder Builder where
                   when (code /= ExitSuccess) $ do
                     fail "tests failed"
 
+                Haddock _ -> do
+                  envs <- haddockEnvs
+                  cmd' envs [path] buildArgs
+
                 _  -> cmd' [path] buildArgs
 
+haddockEnvs :: Action [CmdOption]
+haddockEnvs = do
+    libPath'  <- libPath (vanillaContext Stage1 haddock)
+    distDir'  <- distDir Stage1
+    shlibPath <- liftIO $ makeAbsolute (libPath' -/- distDir')
+    return [ AddEnv "LD_LIBRARY_PATH" shlibPath
+           , AddEnv "DYLD_LIBRARY_PATH" shlibPath ] -- Darwin
+
 -- | Invoke @haddock@ given a path to it and a list of arguments. The arguments
 -- are passed in a response file.
 runHaddock :: FilePath    -- ^ path to @haddock@
@@ -396,7 +409,8 @@ runHaddock :: FilePath    -- ^ path to @
       -> Action ()
 runHaddock haddockPath flagArgs fileInputs = withTempFile $ \tmp -> do
     writeFile' tmp $ escapeArgs fileInputs
-    cmd [haddockPath] flagArgs ('@' : tmp)
+    envs <- haddockEnvs
+    cmd' envs [haddockPath] flagArgs ('@' : tmp)
 
 -- TODO: Some builders are required only on certain platforms. For example,
 -- 'Objdump' is only required on OpenBSD and AIX. Add support for platform
