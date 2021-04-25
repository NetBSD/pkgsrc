$NetBSD: patch-src_Text_Pandoc_Readers_Docx_Combine.hs,v 1.1 2021/04/25 07:50:13 pho Exp $

Fix build with GHC 9.

--- src/Text/Pandoc/Readers/Docx/Combine.hs.orig	2021-04-25 04:23:41.829773600 +0000
+++ src/Text/Pandoc/Readers/Docx/Combine.hs
@@ -61,7 +61,7 @@ import Data.List
 import Data.Bifunctor
 import Data.Sequence ( ViewL (..), ViewR (..), viewl, viewr, spanr, spanl
                      , (><), (|>) )
-import Text.Pandoc.Builder
+import Text.Pandoc.Builder as Builder
 
 data Modifier a = Modifier (a -> a)
                 | AttrModifier (Attr -> a -> a) Attr
@@ -116,12 +116,12 @@ ilModifierAndInnards ils = case viewl $ 
 
 inlinesL :: Inlines -> (Inlines, Inlines)
 inlinesL ils = case viewl $ unMany ils of
-  (s :< sq) -> (singleton s, Many sq)
+  (s :< sq) -> (Builder.singleton s, Many sq)
   _         -> (mempty, ils)
 
 inlinesR :: Inlines -> (Inlines, Inlines)
 inlinesR ils = case viewr $ unMany ils of
-  (sq :> s) -> (Many sq, singleton s)
+  (sq :> s) -> (Many sq, Builder.singleton s)
   _         -> (ils, mempty)
 
 combineInlines :: Inlines -> Inlines -> Inlines
