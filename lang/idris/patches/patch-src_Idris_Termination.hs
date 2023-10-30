$NetBSD: patch-src_Idris_Termination.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Termination.hs.orig	2023-10-30 15:17:42.248510837 +0000
+++ src/Idris/Termination.hs
@@ -19,6 +19,7 @@ import Idris.Error
 import Idris.Options
 import Idris.Output (iWarn)
 
+import Control.Monad
 import Control.Monad.State.Strict
 import Data.Either
 import Data.List
