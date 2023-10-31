$NetBSD: patch-src_Language_PureScript_Sugar_Operators_Common.hs,v 1.1 2023/10/31 07:38:56 pho Exp $

Control.Monad.State no longer re-exports functions from Control.Monad.

--- src/Language/PureScript/Sugar/Operators/Common.hs.orig	2023-10-31 07:22:06.185842060 +0000
+++ src/Language/PureScript/Sugar/Operators/Common.hs
@@ -2,7 +2,7 @@ module Language.PureScript.Sugar.Operato
 
 import Prelude
 
-import Control.Monad.State (guard, join)
+import Control.Monad (guard, join)
 import Control.Monad.Except (MonadError(..))
 
 import Data.Either (rights)
