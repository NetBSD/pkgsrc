$NetBSD: patch-src_Idris_Coverage.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Coverage.hs.orig	2023-10-30 15:15:26.614652915 +0000
+++ src/Idris/Coverage.hs
@@ -17,6 +17,7 @@ import Idris.Delaborate
 import Idris.Elab.Utils
 import Idris.Error
 
+import Control.Monad
 import Control.Monad.State.Strict
 import Data.Char
 import Data.List
