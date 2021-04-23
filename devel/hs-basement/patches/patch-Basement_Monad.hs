$NetBSD: patch-Basement_Monad.hs,v 1.1 2021/04/23 09:26:56 pho Exp $

Fix build with GHC 9.

--- Basement/Monad.hs.orig	2021-04-23 09:18:46.689442468 +0000
+++ Basement/Monad.hs
@@ -29,6 +29,7 @@ module Basement.Monad
     ) where
 
 import qualified Prelude
+import           GHC.Exts (unsafeCoerce#)
 import           GHC.ST
 import           GHC.STRef
 import           GHC.IORef
