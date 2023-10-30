$NetBSD: patch-src_Idris_Erasure.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Erasure.hs.orig	2023-10-30 15:20:01.707406987 +0000
+++ src/Idris/Erasure.hs
@@ -22,6 +22,7 @@ import Prelude hiding (id, (.))
 
 import Control.Arrow
 import Control.Category
+import Control.Monad
 import Control.Monad.State
 import Data.IntMap (IntMap)
 import qualified Data.IntMap as IM
