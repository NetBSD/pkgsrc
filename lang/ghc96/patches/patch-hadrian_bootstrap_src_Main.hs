$NetBSD: patch-hadrian_bootstrap_src_Main.hs,v 1.2 2023/11/02 15:29:31 pho Exp $

Fix build with cabal-install-parsers >= 0.6. This doesn't affect normal
builds. It's only for creating Hadrian bootstrap source archives.

https://gitlab.haskell.org/ghc/ghc/-/merge_requests/11546

--- hadrian/bootstrap/src/Main.hs.orig	2023-09-21 11:30:31.000000000 +0000
+++ hadrian/bootstrap/src/Main.hs
@@ -1,3 +1,5 @@
+{-# Language CPP #-}
+
 module Main (main) where
 
 import Control.Monad      (when)
@@ -85,7 +87,11 @@ main2 meta plan = do
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
