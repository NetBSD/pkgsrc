$NetBSD: patch-src_Language_PureScript_Errors.hs,v 1.1 2023/10/31 07:38:56 pho Exp $

Control.Monad.Writer no longer re-exports data types from Data.Monoid.

--- src/Language/PureScript/Errors.hs.orig	2023-10-31 07:16:13.742377229 +0000
+++ src/Language/PureScript/Errors.hs
@@ -12,7 +12,7 @@ import Control.Lens (both, head1, over)
 import Control.Monad (forM, unless)
 import Control.Monad.Error.Class (MonadError(..))
 import Control.Monad.Trans.State.Lazy (State, evalState, get, put)
-import Control.Monad.Writer (Last(..), MonadWriter(..), censor)
+import Control.Monad.Writer (MonadWriter(..), censor)
 import Data.Bifunctor (first, second)
 import Data.Bitraversable (bitraverse)
 import Data.Char (isSpace)
@@ -27,6 +27,7 @@ import Data.List.NonEmpty qualified as N
 import Data.List.NonEmpty (NonEmpty((:|)))
 import Data.Maybe (maybeToList, fromMaybe, isJust, mapMaybe)
 import Data.Map qualified as M
+import Data.Monoid (Last(..))
 import Data.Ord (Down(..))
 import Data.Set qualified as S
 import Data.Text qualified as T
