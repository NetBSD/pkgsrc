$NetBSD: patch-src_Darcs_Util_Tree_Monad.hs,v 1.1 2023/10/31 10:58:52 pho Exp $

Control.Monad.RWS.Strict no longer re-exports functions from Control.Monad

--- src/Darcs/Util/Tree/Monad.hs.orig	2023-10-31 10:44:12.313929632 +0000
+++ src/Darcs/Util/Tree/Monad.hs
@@ -45,6 +45,7 @@ import Data.Int( Int64 )
 import Data.Maybe( isNothing, isJust )
 
 import qualified Data.ByteString.Lazy as BL
+import Control.Monad
 import Control.Monad.RWS.Strict
 import qualified Data.Map as M
 
