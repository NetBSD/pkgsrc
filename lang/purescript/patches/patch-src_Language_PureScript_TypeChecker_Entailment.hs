$NetBSD: patch-src_Language_PureScript_TypeChecker_Entailment.hs,v 1.2 2024/05/04 09:41:24 pho Exp $

Control.Monad.State no longer re-exports functions from Control.Monad.

--- src/Language/PureScript/TypeChecker/Entailment.hs.orig	2023-11-04 02:42:45.000000000 +0000
+++ src/Language/PureScript/TypeChecker/Entailment.hs
@@ -14,10 +14,11 @@ import Prelude
 import Protolude (ordNub, headMay)
 
 import Control.Arrow (second, (&&&))
+import Control.Monad (foldM, guard, join, zipWithM, zipWithM_, (<=<))
 import Control.Monad.Error.Class (MonadError(..))
-import Control.Monad.State (MonadState(..), MonadTrans(..), StateT(..), evalStateT, execStateT, foldM, gets, guard, join, modify, zipWithM, zipWithM_, (<=<))
+import Control.Monad.State (MonadState(..), MonadTrans(..), StateT(..), evalStateT, execStateT, gets, modify)
 import Control.Monad.Supply.Class (MonadSupply(..))
-import Control.Monad.Writer (Any(..), MonadWriter(..), WriterT(..))
+import Control.Monad.Writer (MonadWriter(..), WriterT(..))
 
 import Data.Either (lefts, partitionEithers)
 import Data.Foldable (for_, fold, toList)
@@ -26,6 +27,7 @@ import Data.Functor (($>), (<&>))
 import Data.List (delete, findIndices, minimumBy, nubBy, sortOn, tails)
 import Data.Maybe (catMaybes, fromMaybe, listToMaybe, mapMaybe)
 import Data.Map qualified as M
+import Data.Monoid (Any(..))
 import Data.Set qualified as S
 import Data.Traversable (for)
 import Data.Text (Text, stripPrefix, stripSuffix)
