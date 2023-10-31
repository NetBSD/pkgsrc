$NetBSD: patch-src_Control_Monad_Supply.hs,v 1.1 2023/10/31 07:38:56 pho Exp $

Control.Monad.Reader no longer re-exports MonadPlus from Control.Monad.

--- src/Control/Monad/Supply.hs.orig	2023-10-31 07:05:24.089544664 +0000
+++ src/Control/Monad/Supply.hs
@@ -6,8 +6,9 @@ module Control.Monad.Supply where
 import Prelude
 
 import Control.Applicative (Alternative)
+import Control.Monad (MonadPlus)
 import Control.Monad.Error.Class (MonadError(..))
-import Control.Monad.Reader (MonadPlus, MonadReader, MonadTrans)
+import Control.Monad.Reader (MonadReader, MonadTrans)
 import Control.Monad.State (StateT(..))
 import Control.Monad.Writer (MonadWriter)
 
