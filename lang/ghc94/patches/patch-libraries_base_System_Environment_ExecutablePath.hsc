$NetBSD: patch-libraries_base_System_Environment_ExecutablePath.hsc,v 1.2 2023/01/21 12:59:54 pho Exp $

Support executablePath on Solaris.

Merge request:
https://gitlab.haskell.org/ghc/ghc/-/merge_requests/9768

--- libraries/base/System/Environment/ExecutablePath.hsc.orig	2023-01-14 16:23:19.153537486 +0000
+++ libraries/base/System/Environment/ExecutablePath.hsc
@@ -38,6 +38,12 @@ import Data.List (isSuffixOf)
 import Foreign.C
 import Foreign.Marshal.Array
 import System.Posix.Internals
+#elif defined(solaris2_HOST_OS)
+import Control.Exception (catch, throw)
+import Foreign.C
+import Foreign.Marshal.Array
+import System.IO.Error (isDoesNotExistError)
+import System.Posix.Internals
 #elif defined(freebsd_HOST_OS) || defined(netbsd_HOST_OS)
 import Control.Exception (catch, throw)
 import Foreign.C
@@ -92,7 +98,7 @@ getExecutablePath :: IO FilePath
 --
 -- If the operating system provides a reliable way to determine the current
 -- executable, return the query action, otherwise return @Nothing@.  The action
--- is defined on FreeBSD, Linux, MacOS, NetBSD, and Windows.
+-- is defined on FreeBSD, Linux, MacOS, NetBSD, Solaris, and Windows.
 --
 -- Even where the query action is defined, there may be situations where no
 -- result is available, e.g. if the executable file was deleted while the
@@ -158,9 +164,9 @@ executablePath = Just (fmap Just getExec
       | otherwise             = throw e
 
 --------------------------------------------------------------------------------
--- Linux
+-- Linux / Solaris
 
-#elif defined(linux_HOST_OS)
+#elif defined(linux_HOST_OS) || defined(solaris2_HOST_OS)
 
 foreign import ccall unsafe "readlink"
     c_readlink :: CString -> CString -> CSize -> IO CInt
@@ -177,6 +183,7 @@ readSymbolicLink file =
                    c_readlink s buf 4096
             peekFilePathLen (buf,fromIntegral len)
 
+#  if defined(linux_HOST_OS)
 getExecutablePath = readSymbolicLink $ "/proc/self/exe"
 
 executablePath = Just (check <$> getExecutablePath) where
@@ -187,6 +194,18 @@ executablePath = Just (check <$> getExec
   check s | "(deleted)" `isSuffixOf` s = Nothing
           | otherwise = Just s
 
+#  elif defined(solaris2_HOST_OS)
+getExecutablePath = readSymbolicLink "/proc/self/path/a.out"
+
+executablePath = Just ((Just <$> getExecutablePath) `catch` f)
+  where
+    -- readlink(2) fails with ENOENT when the executable has been deleted,
+    -- even though the symlink itself still exists according to readdir(3).
+    f e | isDoesNotExistError e = pure Nothing
+        | otherwise             = throw e
+
+#endif
+
 --------------------------------------------------------------------------------
 -- FreeBSD / NetBSD
 
