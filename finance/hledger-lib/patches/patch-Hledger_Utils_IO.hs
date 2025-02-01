$NetBSD: patch-Hledger_Utils_IO.hs,v 1.1 2025/02/01 11:47:18 pho Exp $

Fix a build failure that occurs when the current locale is not *.UTF-8. It
can fail because the file to be embedded may contain non-ASCII characters.

TODO: Upstream this

--- Hledger/Utils/IO.hs.orig	2024-12-06 09:10:33.000000000 +0000
+++ Hledger/Utils/IO.hs
@@ -106,6 +106,7 @@ where
 import           Control.Concurrent (forkIO)
 import           Control.Exception (catch, evaluate, throwIO)
 import           Control.Monad (when, forM, guard, void)
+import           Control.Monad.IO.Class (liftIO)
 import           Data.Char (toLower)
 import           Data.Colour.RGBSpace (RGB(RGB))
 import           Data.Colour.RGBSpace.HSL (lightness)
@@ -124,6 +125,7 @@ import           Data.Time.LocalTime (Lo
 import           Data.Word (Word16)
 import           Debug.Trace (trace)
 import           Foreign.C.Error (Errno(..), ePIPE)
+import           GHC.IO.Encoding (getLocaleEncoding, setLocaleEncoding, utf8)
 import           GHC.IO.Exception (IOException(..), IOErrorType (ResourceVanished))
 import           Language.Haskell.TH.Syntax (Q, Exp)
 import           Safe (headMay, maximumDef)
@@ -278,7 +280,12 @@ readHandlePortably h = do
 
 -- | Like embedFile, but takes a path relative to the package directory.
 embedFileRelative :: FilePath -> Q Exp
-embedFileRelative f = makeRelativeToProject f >>= embedStringFile
+embedFileRelative f = do
+  savedL <- liftIO getLocaleEncoding
+  liftIO $ setLocaleEncoding utf8
+  qexp   <- makeRelativeToProject f >>= embedStringFile
+  liftIO $ setLocaleEncoding savedL
+  pure qexp
 
 -- -- | Like hereFile, but takes a path relative to the package directory.
 -- -- Similar to embedFileRelative ?
