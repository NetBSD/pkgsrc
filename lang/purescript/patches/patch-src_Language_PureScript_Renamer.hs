$NetBSD: patch-src_Language_PureScript_Renamer.hs,v 1.1 2023/10/31 07:38:56 pho Exp $

Control.Monad.State no longer re-exports functions from Control.Monad.

--- src/Language/PureScript/Renamer.hs.orig	2023-10-31 07:14:26.857968378 +0000
+++ src/Language/PureScript/Renamer.hs
@@ -5,7 +5,8 @@ module Language.PureScript.Renamer (rena
 
 import Prelude
 
-import Control.Monad.State (MonadState(..), State, gets, modify, runState, (>=>))
+import Control.Monad ((>=>))
+import Control.Monad.State (MonadState(..), State, gets, modify, runState)
 
 import Data.Functor ((<&>))
 import Data.List (find)
