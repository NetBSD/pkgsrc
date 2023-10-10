$NetBSD: patch-hadrian_bootstrap_src_Main.hs,v 1.1 2023/10/10 14:58:42 pho Exp $

Fix build with cabal-install-parsers >= 0.6. This doesn't affect normal
builds. It's only for creating Hadrian bootstrap source archives.

Not upstreamed yet.

--- hadrian/bootstrap/src/Main.hs.orig	2023-10-10 14:46:57.489617026 +0000
+++ hadrian/bootstrap/src/Main.hs
@@ -1,3 +1,5 @@
+{-# Language CPP #-}
+
 module Main (main) where
 
 import Control.Monad      (when)
@@ -34,7 +36,11 @@ main = do
 
 main1 :: FilePath -> IO ()
 main1 planPath = do
+#if MIN_VERSION_cabal_install_parsers(0, 4, 0)
+    meta <- snd <$> I.cachedHackageMetadata
+#else
     meta <- I.cachedHackageMetadata
+#endif
     plan <- P.decodePlanJson planPath
     main2 meta plan
 
@@ -85,7 +91,11 @@ main2 meta plan = do
                         return
                             ( Hackage
                             , Just $ fromIntegral (I.riRevision relInfo)
+#if MIN_VERSION_cabal_install_parsers(0, 6, 0)
+                            , P.sha256FromByteString $ I.getSHA256 $ I.riCabalHash relInfo
+#else
                             , P.sha256FromByteString $ I.getSHA256 $ I.riCabal relInfo
+#endif
                             )
 
                     Nothing -> case P.uType unit of
