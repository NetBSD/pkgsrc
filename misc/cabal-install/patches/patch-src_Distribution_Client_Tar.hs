$NetBSD: patch-src_Distribution_Client_Tar.hs,v 1.1 2024/04/30 13:17:56 pho Exp $

Fix an API incompatibility with tar-0.6. Upstream has already fixed this in
3.10.3.0:
https://github.com/haskell/cabal/commit/51e6483f95ecb4f395dce36e47af296902a75143

--- src/Distribution/Client/Tar.hs.orig	2024-04-30 13:08:28.902873171 +0000
+++ src/Distribution/Client/Tar.hs
@@ -57,8 +57,15 @@ extractTarGzFile :: FilePath -- ^ Destin
                  -> FilePath -- ^ Tarball
                 -> IO ()
 extractTarGzFile dir expected tar =
-  Tar.unpack dir . Tar.checkTarbomb expected . Tar.read
-  . GZipUtils.maybeDecompress =<< BS.readFile tar
+  Tar.unpackAndCheck
+    ( \x ->
+        SomeException <$> Tar.checkEntryTarbomb expected x
+          <|> SomeException <$> Tar.checkEntrySecurity x
+    )
+    dir
+  . Tar.read
+  . GZipUtils.maybeDecompress
+  =<< BS.readFile tar
 
 instance (Exception a, Exception b) => Exception (Either a b) where
   toException (Left  e) = toException e
