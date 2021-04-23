$NetBSD: patch-Data_ByteArray_ScrubbedBytes.hs,v 1.1 2021/04/23 09:35:57 pho Exp $

Fix build with GHC 9.

--- Data/ByteArray/ScrubbedBytes.hs.orig	2021-04-23 09:28:51.592342938 +0000
+++ Data/ByteArray/ScrubbedBytes.hs
@@ -14,6 +14,7 @@ module Data.ByteArray.ScrubbedBytes
     ( ScrubbedBytes
     ) where
 
+import           GHC.Exts (unsafeCoerce#)
 import           GHC.Types
 import           GHC.Prim
 import           GHC.Ptr
