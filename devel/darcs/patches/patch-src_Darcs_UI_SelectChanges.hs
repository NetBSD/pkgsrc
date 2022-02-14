$NetBSD: patch-src_Darcs_UI_SelectChanges.hs,v 1.1 2022/02/14 14:45:09 pho Exp $

GHC 9.2 cannot seem to unify a rank-2 type "forall wX wY. FL p wX wY -> FL
p wX wY" with just "a -> a". Attempting to do so results in a compilation
error. pho@ has no idea why. Is this a compiler bug???

Work around the issue by expanding "maybe" by hand.

--- src/Darcs/UI/SelectChanges.hs.orig	2022-02-14 13:33:09.429529658 +0000
+++ src/Darcs/UI/SelectChanges.hs
@@ -346,7 +346,9 @@ runInvertibleSelection ps psc = runReade
   -- after selecting with a splitter, the results may not be canonical
   canonizeAfterSplitter :: (FL p :> FL p) wA wB -> (FL p :> FL p) wA wB
   canonizeAfterSplitter (x :> y) =
-    let canonizeIfNeeded = maybe id canonizeSplit mspl
+    let canonizeIfNeeded = \a -> case mspl of
+                                   Just spl -> canonizeSplit spl a
+                                   Nothing  -> a
     in canonizeIfNeeded x :> canonizeIfNeeded y
 
   -- retrieve the results of patch selection
