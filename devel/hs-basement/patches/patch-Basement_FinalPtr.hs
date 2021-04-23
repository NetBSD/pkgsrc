$NetBSD: patch-Basement_FinalPtr.hs,v 1.1 2021/04/23 09:26:56 pho Exp $

Fix build with GHC 9.

--- Basement/FinalPtr.hs.orig	2021-04-23 09:20:47.062262725 +0000
+++ Basement/FinalPtr.hs
@@ -25,7 +25,7 @@ module Basement.FinalPtr
     ) where
 
 import GHC.Ptr
-import GHC.ForeignPtr
+import GHC.ForeignPtr (ForeignPtr, castForeignPtr, unsafeForeignPtrToPtr, touchForeignPtr)
 import GHC.IO
 import Basement.Monad
 import Basement.Compat.Primitive
