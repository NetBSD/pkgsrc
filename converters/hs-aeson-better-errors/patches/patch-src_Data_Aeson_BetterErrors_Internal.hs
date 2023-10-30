$NetBSD: patch-src_Data_Aeson_BetterErrors_Internal.hs,v 1.3 2023/10/30 13:31:38 pho Exp $

Prelude no longer re-exports functions from Control.Monad.

--- src/Data/Aeson/BetterErrors/Internal.hs.orig	2023-10-30 13:30:13.086283230 +0000
+++ src/Data/Aeson/BetterErrors/Internal.hs
@@ -12,6 +12,7 @@ import Data.Foldable (foldMap)
 #endif
 
 import Control.Arrow (left)
+import Control.Monad
 import Control.Monad.Identity
 import Control.Monad.Reader
 import Control.Monad.Trans.Except
