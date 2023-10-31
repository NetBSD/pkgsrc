$NetBSD: patch-src_Darcs_Util_Compat.hs,v 1.1 2023/10/31 10:58:52 pho Exp $

Fix build with GHC 9.6 (unix-2.8.1.0).

--- src/Darcs/Util/Compat.hs.orig	2023-10-31 10:50:00.729609111 +0000
+++ src/Darcs/Util/Compat.hs
@@ -20,7 +20,7 @@ import System.Directory ( getCurrentDire
 import System.IO.Error ( mkIOError, alreadyExistsErrorType )
 import System.Posix.Files ( stdFileMode )
 import System.Posix.IO ( openFd, closeFd,
-                         defaultFileFlags, exclusive,
+                         defaultFileFlags, exclusive, creat,
                          OpenMode(WriteOnly) )
 
 import Darcs.Util.SignalHandler ( stdoutIsAPipe )
@@ -63,9 +63,9 @@ maybeRelink src dst =
 
 sloppyAtomicCreate :: FilePath -> IO ()
 sloppyAtomicCreate fp
-    = do fd <- openFd fp WriteOnly (Just stdFileMode) flags
+    = do fd <- openFd fp WriteOnly flags
          closeFd fd
-  where flags = defaultFileFlags { exclusive = True }
+  where flags = defaultFileFlags { exclusive = True, creat = Just stdFileMode }
 
 atomicCreate :: FilePath -> IO ()
 atomicCreate fp = withCString fp $ \cstr -> do
