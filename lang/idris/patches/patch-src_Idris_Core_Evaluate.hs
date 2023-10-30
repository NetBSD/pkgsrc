$NetBSD: patch-src_Idris_Core_Evaluate.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Core/Evaluate.hs.orig	2023-10-30 15:01:22.103657898 +0000
+++ src/Idris/Core/Evaluate.hs
@@ -37,6 +37,7 @@ module Idris.Core.Evaluate(normalise, no
 import Idris.Core.CaseTree
 import Idris.Core.TT
 
+import Control.Monad
 import Control.Monad.State
 import Data.List
 import Data.Maybe (listToMaybe)
