$NetBSD: patch-Basement_Block_Base.hs,v 1.1 2021/04/23 09:26:56 pho Exp $

Fix build with GHC 9.

--- Basement/Block/Base.hs.orig	2021-04-23 09:22:04.400736590 +0000
+++ Basement/Block/Base.hs
@@ -36,6 +36,7 @@ module Basement.Block.Base
     , unsafeRecast
     ) where
 
+import           GHC.Exts (unsafeCoerce#)
 import           GHC.Prim
 import           GHC.Types
 import           GHC.ST
