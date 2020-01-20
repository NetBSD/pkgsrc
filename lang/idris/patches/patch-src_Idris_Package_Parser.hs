$NetBSD: patch-src_Idris_Package_Parser.hs,v 1.1 2020/01/20 23:32:38 pho Exp $

Fix build with GHC 8.8

--- src/Idris/Package/Parser.hs.orig	2020-01-20 13:57:35.633471081 +0000
+++ src/Idris/Package/Parser.hs
@@ -64,7 +64,7 @@ pPkgName = (either fail pure . pkgName =
 -- | Parses a filename.
 -- |
 -- | Treated for now as an identifier or a double-quoted string.
-filename :: Parsing m => m String
+filename :: (Parsing m, MonadFail m) => m String
 filename = (do
                 -- Treat a double-quoted string as a filename to support spaces.
                 -- This also moves away from tying filenames to identifiers, so
