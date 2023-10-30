$NetBSD: patch-src_Idris_PartialEval.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/PartialEval.hs.orig	2023-10-30 15:18:39.376326262 +0000
+++ src/Idris/PartialEval.hs
@@ -19,6 +19,7 @@ import Idris.Core.Evaluate
 import Idris.Core.TT
 import Idris.Delaborate
 
+import Control.Monad
 import Control.Monad.State
 
 -- | Data type representing binding-time annotations for partial evaluation of arguments
