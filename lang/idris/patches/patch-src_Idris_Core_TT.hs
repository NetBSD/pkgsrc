$NetBSD: patch-src_Idris_Core_TT.hs,v 1.3 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Core/TT.hs.orig	2023-10-30 14:59:16.958812363 +0000
+++ src/Idris/Core/TT.hs
@@ -70,6 +70,7 @@ import qualified Prelude as S (Semigroup
 import Control.Applicative (Alternative, Applicative(..))
 import qualified Control.Applicative as A (Alternative(..))
 import Control.DeepSeq (($!!))
+import Control.Monad
 import qualified Control.Monad.Fail as Fail
 import Control.Monad.State.Strict
 import Data.Binary hiding (get, put)
