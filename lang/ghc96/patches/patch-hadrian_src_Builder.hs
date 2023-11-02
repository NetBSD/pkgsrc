$NetBSD: patch-hadrian_src_Builder.hs,v 1.2 2023/11/02 14:32:04 pho Exp $

Hunk #0, #2:
    This is pkgsrc-specific. We build haddock as a dynamically-linked
    executable but it doesn't contain an rpath to our not-yet-installed
    shared libraries. This is usually not a problem because Hadrian embeds
    relative rpaths (i.e. $ORIGIN) in dynamically-linked objects but we
    patch Hadrian not to do that.

Hunk #1:

    primop.txt contains Unicode characters. Don't assume the current locale
    is "*.UTF-8".

    > _build/stage0/compiler/build/primops.txt: hGetContents: invalid argument (cannot decode byte sequence starting from 226)

    https://gitlab.haskell.org/ghc/ghc/-/merge_requests/11544

--- hadrian/src/Builder.hs.orig	2023-09-21 11:30:31.000000000 +0000
+++ hadrian/src/Builder.hs
@@ -31,6 +31,7 @@ import Hadrian.Utilities
 import Oracles.Setting (bashPath)
 import System.Exit
 import System.IO (stderr)
+import System.Directory (makeAbsolute)
 
 import Base
 import Context
@@ -333,8 +334,8 @@ instance H.Builder Builder where
                 GenApply -> captureStdout
 
                 GenPrimopCode -> do
-                    stdin <- readFile' input
-                    Stdout stdout <- cmd' (Stdin stdin) [path] buildArgs
+                    need [input]
+                    Stdout stdout <- cmd' (FileStdin input) [path] buildArgs
                     -- see Note [Capture stdout as a ByteString]
                     writeFileChangedBS output stdout
 
@@ -383,6 +384,14 @@ instance H.Builder Builder where
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
