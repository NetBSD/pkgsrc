$NetBSD: patch-src_Language_PureScript_AST_Declarations.hs,v 1.1 2022/02/23 16:19:45 pho Exp $

Fix build with GHC 9.2

--- src/Language/PureScript/AST/Declarations.hs.orig	2022-02-20 14:45:26.085101440 +0000
+++ src/Language/PureScript/AST/Declarations.hs
@@ -821,9 +821,9 @@ newtype AssocList k t = AssocList { runA
   deriving (Show, Eq, Ord, Foldable, Functor, Traversable)
 
 $(deriveJSON (defaultOptions { sumEncoding = ObjectWithSingleField }) ''NameSource)
+$(deriveJSON (defaultOptions { sumEncoding = ObjectWithSingleField }) ''ExportSource)
 $(deriveJSON (defaultOptions { sumEncoding = ObjectWithSingleField }) ''DeclarationRef)
 $(deriveJSON (defaultOptions { sumEncoding = ObjectWithSingleField }) ''ImportDeclarationType)
-$(deriveJSON (defaultOptions { sumEncoding = ObjectWithSingleField }) ''ExportSource)
 
 isTrueExpr :: Expr -> Bool
 isTrueExpr (Literal _ (BooleanLiteral True)) = True
