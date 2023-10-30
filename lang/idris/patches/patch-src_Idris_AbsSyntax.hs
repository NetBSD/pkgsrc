$NetBSD: patch-src_Idris_AbsSyntax.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/AbsSyntax.hs.orig	2023-10-30 15:14:13.810516673 +0000
+++ src/Idris/AbsSyntax.hs
@@ -27,6 +27,7 @@ import System.Directory (canonicalizePat
 import System.IO
 
 import Control.Applicative
+import Control.Monad
 import Control.Monad.State
 import Prelude hiding (Applicative, Foldable, Traversable, (<$>))
 
