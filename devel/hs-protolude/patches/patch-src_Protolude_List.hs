$NetBSD: patch-src_Protolude_List.hs,v 1.1 2025/02/01 09:22:10 pho Exp $

Fix build on GHC 9.10:
https://github.com/protolude/protolude/issues/149

--- src/Protolude/List.hs.orig	2025-02-01 09:20:44.880216971 +0000
+++ src/Protolude/List.hs
@@ -20,7 +20,7 @@ import Data.List (groupBy, sortBy)
 import Data.Maybe (Maybe (Nothing))
 import Data.Ord (Ord, comparing)
 import qualified Data.Set as Set
-import GHC.Num ((*), (+), Num)
+import Prelude ((*), (+), Num)
 
 head :: (Foldable f) => f a -> Maybe a
 head = foldr (\x _ -> pure x) Nothing
