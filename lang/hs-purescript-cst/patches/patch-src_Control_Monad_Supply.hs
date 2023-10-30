$NetBSD: patch-src_Control_Monad_Supply.hs,v 1.1 2023/10/30 10:07:06 pho Exp $

Prelude no longer re-exports MonadPlus from Control.Monad

--- src/Control/Monad/Supply.hs.orig	2023-10-30 10:02:40.533191403 +0000
+++ src/Control/Monad/Supply.hs
@@ -6,6 +6,7 @@ module Control.Monad.Supply where
 import Prelude.Compat
 
 import Control.Applicative
+import Control.Monad
 import Control.Monad.Error.Class (MonadError(..))
 import Control.Monad.Reader
 import Control.Monad.State
