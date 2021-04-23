$NetBSD: patch-Data_ByteArray_Bytes.hs,v 1.1 2021/04/23 09:35:57 pho Exp $

Fix build with GHC 9.

--- Data/ByteArray/Bytes.hs.orig	2021-04-23 09:28:23.358632857 +0000
+++ Data/ByteArray/Bytes.hs
@@ -16,6 +16,7 @@ module Data.ByteArray.Bytes
     ( Bytes
     ) where
 
+import           GHC.Exts (unsafeCoerce#)
 import           GHC.Types
 import           GHC.Prim
 import           GHC.Ptr
