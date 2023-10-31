$NetBSD: patch-src_Language_PureScript_TypeChecker_Monad.hs,v 1.1 2023/10/31 07:38:56 pho Exp $

Control.Monad.State no longer re-exports functions from Control.Monad.

--- src/Language/PureScript/TypeChecker/Monad.hs.orig	2023-10-31 07:18:13.109321834 +0000
+++ src/Language/PureScript/TypeChecker/Monad.hs
@@ -8,8 +8,9 @@ module Language.PureScript.TypeChecker.M
 import Prelude
 
 import Control.Arrow (second)
+import Control.Monad (forM_, guard, join, when, (<=<))
 import Control.Monad.Error.Class (MonadError(..))
-import Control.Monad.State (MonadState(..), StateT(..), forM_, gets, guard, join, modify, when, (<=<))
+import Control.Monad.State (MonadState(..), StateT(..), gets, modify)
 import Control.Monad.Writer.Class (MonadWriter(..), censor)
 
 import Data.Maybe (fromMaybe)
