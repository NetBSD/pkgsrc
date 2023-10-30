$NetBSD: patch-src_Idris_Core_Typecheck.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Core/Typecheck.hs.orig	2023-10-30 15:04:06.947604795 +0000
+++ src/Idris/Core/Typecheck.hs
@@ -14,6 +14,7 @@ module Idris.Core.Typecheck where
 import Idris.Core.Evaluate
 import Idris.Core.TT
 
+import Control.Monad
 import Control.Monad.State
 
 -- To check conversion, normalise each term wrt the current environment.
