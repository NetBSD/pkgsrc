$NetBSD: patch-src_IRTS_Compiler.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/IRTS/Compiler.hs.orig	2023-10-30 15:22:07.966102866 +0000
+++ src/IRTS/Compiler.hs
@@ -32,6 +32,7 @@ import IRTS.Simplified
 import Prelude hiding (id, (.))
 
 import Control.Category
+import Control.Monad
 import Control.Monad.State
 import Data.List
 import qualified Data.Map as M
