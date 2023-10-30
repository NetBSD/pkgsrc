$NetBSD: patch-src_Idris_Core_ProofTerm.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Core/ProofTerm.hs.orig	2023-10-30 15:03:14.424585697 +0000
+++ src/Idris/Core/ProofTerm.hs
@@ -19,6 +19,7 @@ module Idris.Core.ProofTerm(
 import Idris.Core.Evaluate
 import Idris.Core.TT
 
+import Control.Monad
 import Control.Monad.State.Strict
 
 -- | A zipper over terms, in order to efficiently update proof terms.
