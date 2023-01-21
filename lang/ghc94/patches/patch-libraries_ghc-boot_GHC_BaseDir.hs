$NetBSD: patch-libraries_ghc-boot_GHC_BaseDir.hs,v 1.2 2023/01/21 12:59:54 pho Exp $

Make getBaseDir less platform-dependent by making use of base-4.17
`executablePath` when possible, and falling back on `getExecutablePath`
when it's not available.

Merge request:
https://gitlab.haskell.org/ghc/ghc/-/merge_requests/9768

--- libraries/ghc-boot/GHC/BaseDir.hs.orig	2023-01-14 17:06:00.667592015 +0000
+++ libraries/ghc-boot/GHC/BaseDir.hs
@@ -12,18 +12,20 @@
 -- installation location at build time. ghc-pkg also can expand those variables
 -- and so needs the top dir location to do that too.
 
-module GHC.BaseDir where
+module GHC.BaseDir
+  ( expandTopDir
+  , expandPathVar
+  , getBaseDir
+  ) where
 
 import Prelude -- See Note [Why do we import Prelude here?]
 
 import Data.List (stripPrefix)
 import System.FilePath
 
--- Windows
-#if defined(mingw32_HOST_OS)
-import System.Environment (getExecutablePath)
--- POSIX
-#elif defined(darwin_HOST_OS) || defined(linux_HOST_OS) || defined(freebsd_HOST_OS) || defined(openbsd_HOST_OS) || defined(netbsd_HOST_OS)
+#if MIN_VERSION_base(4,17,0)
+import System.Environment (executablePath)
+#else
 import System.Environment (getExecutablePath)
 #endif
 
@@ -42,17 +44,23 @@ expandPathVar var value str
 expandPathVar var value (x:xs) = x : expandPathVar var value xs
 expandPathVar _ _ [] = []
 
+#if !MIN_VERSION_base(4,17,0)
+-- Polyfill for executablePath
+executablePath :: Maybe (IO (Maybe FilePath))
+executablePath = Just (Just <$> getExecutablePath)
+#endif
+
 -- | Calculate the location of the base dir
 getBaseDir :: IO (Maybe String)
 #if defined(mingw32_HOST_OS)
-getBaseDir = Just . (\p -> p </> "lib") . rootDir <$> getExecutablePath
+getBaseDir = maybe (pure Nothing) ((((</> "lib") . rootDir) <$>) <$>) executablePath
   where
     -- locate the "base dir" when given the path
     -- to the real ghc executable (as opposed to symlink)
     -- that is running this function.
     rootDir :: FilePath -> FilePath
     rootDir = takeDirectory . takeDirectory . normalise
-#elif defined(darwin_HOST_OS) || defined(linux_HOST_OS) || defined(freebsd_HOST_OS) || defined(openbsd_HOST_OS) || defined(netbsd_HOST_OS)
+#else
 -- on unix, this is a bit more confusing.
 -- The layout right now is something like
 --
@@ -64,14 +72,15 @@ getBaseDir = Just . (\p -> p </> "lib")
 -- As such, we first need to find the absolute location to the
 -- binary.
 --
--- getExecutablePath will return (3). One takeDirectory will
+-- executablePath will return (3). One takeDirectory will
 -- give use /lib/ghc-X.Y.Z/bin, and another will give us (4).
 --
 -- This of course only works due to the current layout. If
 -- the layout is changed, such that we have ghc-X.Y.Z/{bin,lib}
 -- this would need to be changed accordingly.
 --
-getBaseDir = Just . (\p -> p </> "lib") . takeDirectory . takeDirectory <$> getExecutablePath
-#else
-getBaseDir = return Nothing
+getBaseDir = maybe (pure Nothing) ((((</> "lib") . rootDir) <$>) <$>) executablePath
+  where
+    rootDir :: FilePath -> FilePath
+    rootDir = takeDirectory . takeDirectory
 #endif
