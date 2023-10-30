$NetBSD: patch-src_Idris_Imports.hs,v 1.1 2023/10/30 15:39:57 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Idris/Imports.hs.orig	2023-10-30 15:16:52.335069114 +0000
+++ src/Idris/Imports.hs
@@ -16,6 +16,7 @@ import Idris.Core.TT
 import Idris.Error
 import IRTS.System (getIdrisLibDir)
 
+import Control.Monad
 import Control.Monad.State.Strict
 import Data.Char (isAlpha, isDigit, toLower)
 import Data.List (isSuffixOf)
