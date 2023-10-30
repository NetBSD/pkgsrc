$NetBSD: patch-src_Idris_Core_ProofState.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Core/ProofState.hs.orig	2023-10-30 15:09:52.111432787 +0000
+++ src/Idris/Core/ProofState.hs
@@ -28,6 +28,7 @@ import Idris.Core.WHNF
 
 import Util.Pretty hiding (fill)
 
+import Control.Monad
 import Control.Monad.State.Strict
 import Data.List
 
