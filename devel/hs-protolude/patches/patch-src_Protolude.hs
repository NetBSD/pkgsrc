$NetBSD: patch-src_Protolude.hs,v 1.1 2022/02/23 16:18:22 pho Exp $

Fix build with GHC 9.2

--- src/Protolude.hs.orig	2022-02-20 14:27:37.821200859 +0000
+++ src/Protolude.hs
@@ -267,8 +267,10 @@ import Data.List.NonEmpty as List (
 import Data.Semigroup as Semigroup (
     Semigroup(sconcat, stimes)
   , WrappedMonoid
+#if !MIN_VERSION_base(4,16,0)
   , Option(..)
   , option
+#endif
   , diff
   , cycle1
   , stimesMonoid
