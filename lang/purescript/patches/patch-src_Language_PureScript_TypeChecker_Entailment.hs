$NetBSD: patch-src_Language_PureScript_TypeChecker_Entailment.hs,v 1.1 2023/10/31 07:38:56 pho Exp $

Control.Monad.State no longer re-exports functions from Control.Monad.

--- src/Language/PureScript/TypeChecker/Entailment.hs.orig	2023-10-31 07:20:17.099461014 +0000
+++ src/Language/PureScript/TypeChecker/Entailment.hs
@@ -14,10 +14,11 @@ import Prelude
 import Protolude (ordNub)
 
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
@@ -26,6 +27,7 @@ import Data.Functor (($>))
 import Data.List (delete, findIndices, minimumBy, nubBy, sortOn, tails)
 import Data.Maybe (catMaybes, fromMaybe, listToMaybe, mapMaybe)
 import Data.Map qualified as M
+import Data.Monoid (Any(..))
 import Data.Set qualified as S
 import Data.Traversable (for)
 import Data.Text (Text, stripPrefix, stripSuffix)
