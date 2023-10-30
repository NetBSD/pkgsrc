$NetBSD: patch-src_Idris_Package_Parser.hs,v 1.2 2023/10/30 15:39:57 pho Exp $

Fix build with GHC 9.6

--- src/Idris/Package/Parser.hs.orig	2001-09-09 01:46:40.000000000 +0000
+++ src/Idris/Package/Parser.hs
@@ -19,6 +19,7 @@ import Idris.Parser.Helpers (Parser, Par
                              someSpace, stringLiteral)
 
 import Control.Applicative
+import Control.Monad
 import Control.Monad.State.Strict
 import Data.List (union)
 import qualified Options.Applicative as Opts
@@ -64,7 +65,7 @@ pPkgName = (either fail pure . pkgName =
 -- | Parses a filename.
 -- |
 -- | Treated for now as an identifier or a double-quoted string.
-filename :: Parsing m => m String
+filename :: (Parsing m, MonadFail m) => m String
 filename = (do
                 -- Treat a double-quoted string as a filename to support spaces.
                 -- This also moves away from tying filenames to identifiers, so
