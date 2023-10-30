$NetBSD: patch-src_Idris_Prover.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Prover.hs.orig	2023-10-30 15:22:58.734795932 +0000
+++ src/Idris/Prover.hs
@@ -39,6 +39,7 @@ import Idris.TypeSearch (searchByType)
 import Util.Pretty
 
 import Control.DeepSeq
+import Control.Monad
 import Control.Monad.State.Strict
 import System.Console.Haskeline
 import System.Console.Haskeline.History
