$NetBSD: patch-src_Distribution_Client_FileMonitor.hs,v 1.1 2022/02/11 17:49:05 pho Exp $

Cabal-3.6.0.0 shipped with GHC 9.2.1 exports neither Tag nor
structuredDecodeTriple so we have no choice but to kill the entire
file-watching machinery. pho@ has no idea how it ended up in this
situation. The upstream has never released Cabal with this broken
Distribution.Utils.Structured apparently???

--- src/Distribution/Client/FileMonitor.hs.orig	2022-02-08 02:09:01.086511380 +0000
+++ src/Distribution/Client/FileMonitor.hs
@@ -63,7 +63,7 @@ import           Distribution.Compat.Tim
 import           Distribution.Client.Glob
 import           Distribution.Simple.Utils (handleDoesNotExist, writeFileAtomic)
 import           Distribution.Client.Utils (mergeBy, MergeResult(..))
-import           Distribution.Utils.Structured (structuredEncode, Tag (..))
+import           Distribution.Utils.Structured (structuredEncode)
 import           System.FilePath
 import           System.Directory
 import           System.IO
@@ -508,19 +508,7 @@ checkFileMonitorChanged
 structuredDecodeTriple
   :: forall a b c. (Structured a, Structured b, Structured c, Binary.Binary a, Binary.Binary b, Binary.Binary c)
   => BS.ByteString -> Either String (a, b, Either String c)
-structuredDecodeTriple lbs =
-  let partialDecode =
-         (`runGetOrFail` lbs) $ do
-            (_ :: Tag (a,b,c)) <- Binary.get
-            (a :: a) <- Binary.get
-            (b :: b) <- Binary.get
-            pure (a, b)
-      cleanEither (Left (_, pos, msg)) = Left ("Data.Binary.Get.runGet at position " ++ show pos ++ ": " ++ msg)
-      cleanEither (Right (_,_,v))     = Right v
-
-  in case partialDecode of
-       Left (_, pos, msg) ->  Left ("Data.Binary.Get.runGet at position " ++ show pos ++ ": " ++ msg)
-       Right (lbs', _, (x,y)) -> Right (x, y, cleanEither $ runGetOrFail (Binary.get :: Binary.Get c) lbs')
+structuredDecodeTriple _ = Left "cabal-install cannot currently monitor changes in files"
 
 -- | Helper for reading the cache file.
 --
