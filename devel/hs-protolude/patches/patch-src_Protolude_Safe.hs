$NetBSD: patch-src_Protolude_Safe.hs,v 1.1 2025/02/01 09:22:10 pho Exp $

Fix build on GHC 9.10:
https://github.com/protolude/protolude/issues/149

--- src/Protolude/Safe.hs.orig	2025-02-01 09:19:33.810599346 +0000
+++ src/Protolude/Safe.hs
@@ -35,7 +35,7 @@ import Data.Either (Either(Left, Right))
 import Data.Function ((.))
 import Data.List (null, head, last, tail, init, maximum, minimum, foldr1, foldl1, foldl1', (++))
 
-import GHC.Num ((-))
+import Prelude ((-))
 import GHC.Show (show)
 
 liftMay :: (a -> Bool) -> (a -> b) -> (a -> Maybe b)
