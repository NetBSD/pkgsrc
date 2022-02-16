$NetBSD: patch-src_Ide_Plugin_Literals.hs,v 1.1 2022/02/16 10:17:01 pho Exp $

Fix build with GHC 9.2 API: The structure of FractionalLit has changed.

--- src/Ide/Plugin/Literals.hs.orig	2022-02-15 15:42:54.956463717 +0000
+++ src/Ide/Plugin/Literals.hs
@@ -18,6 +18,7 @@ import           Development.IDE.Graph.C
 import qualified GHC.Generics                  as GHC
 import           Generics.SYB                  (Data, Typeable, everything,
                                                 extQ)
+import GHC.Types.SourceText (rationalFromFractionalLit)
 
 -- data type to capture what type of literal we are dealing with
 -- provides location and possibly source text (for OverLits) as well as it's value
@@ -85,7 +86,7 @@ fromIntegralLit :: RealSrcSpan -> Integr
 fromIntegralLit s IL{..} = fmap (\txt' -> IntLiteral s txt' il_value) (fromSourceText il_text)
 
 fromFractionalLit  :: RealSrcSpan -> FractionalLit -> Maybe Literal
-fromFractionalLit s FL{..} = fmap (\txt' -> FracLiteral s txt' fl_value) (fromSourceText fl_text)
+fromFractionalLit s frac@FL{..} = fmap (\txt' -> FracLiteral s txt' $ rationalFromFractionalLit frac) (fromSourceText fl_text)
 
 fromSourceText :: SourceText -> Maybe Text
 fromSourceText = \case
@@ -116,5 +117,5 @@ literalToString = \case
 overLitToString :: OverLitVal -> String
 overLitToString = \case
      HsIntegral int -> case int of { IL{il_value} -> "IntegralOverLit: " <> show il_value}
-     HsFractional frac -> case frac of { FL{fl_value} -> "RationalOverLit: " <> show fl_value}
+     HsFractional frac -> case rationalFromFractionalLit frac of { fl_value -> "RationalOverLit: " <> show fl_value}
      HsIsString _ str -> "HIsString: " <> show str
