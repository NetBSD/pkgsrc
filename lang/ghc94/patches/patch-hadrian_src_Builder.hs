$NetBSD: patch-hadrian_src_Builder.hs,v 1.1 2023/01/21 04:49:25 pho Exp $

We build haddock as a dynamically-linked executable but it doesn't contain
an rpath to our not-yet-installed shared libraries. This is usually not a
problem because Hadrian embeds relative rpaths (i.e. $ORIGIN) in
dynamically-linked objects but we patch Hadrian not to do that.

--- hadrian/src/Builder.hs.orig	2023-01-11 18:03:24.816170940 +0000
+++ hadrian/src/Builder.hs
@@ -31,6 +31,7 @@ import Hadrian.Utilities
 import Oracles.Setting (bashPath)
 import System.Exit
 import System.IO (stderr)
+import System.Directory (makeAbsolute)
 
 import Base
 import Context
@@ -381,6 +382,14 @@ instance H.Builder Builder where
                   when (code /= ExitSuccess) $ do
                     fail "tests failed"
 
+                Haddock _ -> do
+                  libPath'  <- libPath (vanillaContext Stage1 haddock)
+                  distDir'  <- distDir Stage1
+                  shlibPath <- liftIO $ makeAbsolute (libPath' -/- distDir')
+                  let envs = [ AddEnv "LD_LIBRARY_PATH" shlibPath
+                             , AddEnv "DYLD_LIBRARY_PATH" shlibPath ] -- Darwin
+                  cmd' envs [path] buildArgs
+
                 _  -> cmd' [path] buildArgs
 
 -- TODO: Some builders are required only on certain platforms. For example,
