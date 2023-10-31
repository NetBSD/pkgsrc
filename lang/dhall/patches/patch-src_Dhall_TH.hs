$NetBSD: patch-src_Dhall_TH.hs,v 1.1 2023/10/31 08:46:24 pho Exp $

Fix build with GHC 9.6 (template-haskell-2.20.0.0).

--- src/Dhall/TH.hs.orig	2023-10-31 08:15:53.407444449 +0000
+++ src/Dhall/TH.hs
@@ -263,7 +263,7 @@ toDeclaration generateOptions@GenerateOp
 
         interpretOptions = generateToInterpretOptions generateOptions typ
 
-        toTypeVar (V n i) = Syntax.PlainTV $ Syntax.mkName (Text.unpack n ++ show i)
+        toTypeVar (V n i) = Syntax.PlainTV (Syntax.mkName (Text.unpack n ++ show i)) ()
 
         toDataD typeName typeParams constructors = do
             let name = Syntax.mkName (Text.unpack typeName)
