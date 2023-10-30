$NetBSD: patch-src_Idris_Core_Elaborate.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Core/Elaborate.hs.orig	2023-10-30 15:13:01.357690530 +0000
+++ src/Idris/Core/Elaborate.hs
@@ -24,6 +24,7 @@ import Idris.Core.TT
 import Idris.Core.Typecheck
 import Idris.Core.Unify
 
+import Control.Monad
 import Control.Monad.State.Strict
 import Data.List
 
