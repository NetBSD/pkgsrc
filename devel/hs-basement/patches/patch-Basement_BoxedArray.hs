$NetBSD: patch-Basement_BoxedArray.hs,v 1.1 2021/04/23 09:26:56 pho Exp $

Fix build with GHC 9.

--- Basement/BoxedArray.hs.orig	2021-04-23 09:22:37.097665600 +0000
+++ Basement/BoxedArray.hs
@@ -74,6 +74,7 @@ module Basement.BoxedArray
     , builderBuild_
     ) where
 
+import           GHC.Exts (unsafeCoerce#)
 import           GHC.Prim
 import           GHC.Types
 import           GHC.ST
