$NetBSD: patch-src_Idris_DSL.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/DSL.hs.orig	2023-10-30 15:16:11.630050396 +0000
+++ src/Idris/DSL.hs
@@ -13,6 +13,7 @@ module Idris.DSL (debindApp, desugar) wh
 import Idris.AbsSyntax
 import Idris.Core.TT
 
+import Control.Monad
 import Control.Monad.State.Strict
 import Data.Generics.Uniplate.Data (transform)
 
