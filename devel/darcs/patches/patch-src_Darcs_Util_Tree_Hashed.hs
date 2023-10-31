$NetBSD: patch-src_Darcs_Util_Tree_Hashed.hs,v 1.1 2023/10/31 10:58:52 pho Exp $

Control.Monad.State.Strict no longer re-exports functions from Control.Monad

--- src/Darcs/Util/Tree/Hashed.hs.orig	2023-10-31 10:45:13.546672960 +0000
+++ src/Darcs/Util/Tree/Hashed.hs
@@ -40,7 +40,8 @@ import qualified Data.ByteString as B
 
 import Data.List( sortBy )
 import Data.Maybe( fromJust, isJust )
-import Control.Monad.State.Strict (liftIO,when,unless)
+import Control.Monad (when, unless)
+import Control.Monad.State.Strict (liftIO)
 
 import Darcs.Prelude
 
