$NetBSD: patch-src_Idris_Core_TT.hs,v 1.1 2020/01/20 23:32:38 pho Exp $

Fix build with GHC 8.8

--- src/Idris/Core/TT.hs.orig	2020-01-20 12:53:32.332100994 +0000
+++ src/Idris/Core/TT.hs
@@ -70,6 +70,7 @@ import qualified Prelude as S (Semigroup
 import Control.Applicative (Alternative, Applicative(..))
 import qualified Control.Applicative as A (Alternative(..))
 import Control.DeepSeq (($!!))
+import Control.Monad.Fail
 import Control.Monad.State.Strict
 import Data.Binary hiding (get, put)
 import Data.Char
@@ -324,6 +325,8 @@ bindTC x k = case x of
 instance Monad TC where
     return x = OK x
     x >>= k = bindTC x k
+
+instance MonadFail TC where
     fail e = Error (InternalMsg e)
 
 instance MonadPlus TC where
