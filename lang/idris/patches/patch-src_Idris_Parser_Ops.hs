$NetBSD: patch-src_Idris_Parser_Ops.hs,v 1.1 2020/01/20 23:32:38 pho Exp $

Fix build with GHC 8.8

--- src/Idris/Parser/Ops.hs.orig	2020-01-20 13:37:19.852674734 +0000
+++ src/Idris/Parser/Ops.hs
@@ -104,7 +104,7 @@ table fixes
     ;
 @
 -}
-backtickOperator :: (Parsing m, MonadState IState m) => m Name
+backtickOperator :: (Parsing m, MonadState IState m, MonadFail m) => m Name
 backtickOperator = P.between (indentGt *> lchar '`') (indentGt *> lchar '`') name
 
 {- | Parses an operator name (either a symbolic name or a backtick-quoted name)
@@ -116,7 +116,7 @@ backtickOperator = P.between (indentGt *
     ;
 @
 -}
-operatorName :: (Parsing m, MonadState IState m) => m Name
+operatorName :: (Parsing m, MonadState IState m, MonadFail m) => m Name
 operatorName =     sUN <$> symbolicOperator
                <|> backtickOperator
 
@@ -131,7 +131,7 @@ operatorName =     sUN <$> symbolicOpera
 @
 
 -}
-operatorFront :: Parsing m => m Name
+operatorFront :: (Parsing m, MonadFail m) => m Name
 operatorFront = do     P.try $ lchar '(' *> (eqTy <$ reservedOp "=") <* lchar ')'
                    <|> maybeWithNS (lchar '(' *> symbolicOperator <* lchar ')') []
 
@@ -141,7 +141,7 @@ operatorFront = do     P.try $ lchar '('
   FnName ::= Name | OperatorFront;
 @
 -}
-fnName :: (Parsing m, MonadState IState m) => m Name
+fnName :: (Parsing m, MonadState IState m, MonadFail m) => m Name
 fnName = P.try operatorFront <|> name <?> "function name"
 
 {- | Parses a fixity declaration
@@ -235,7 +235,7 @@ invalidOperators :: [String]
 invalidOperators = [":", "=>", "->", "<-", "=", "?=", "|", "**", "==>", "\\", "%", "~", "?", "!", "@"]
 
 -- | Parses an operator
-symbolicOperator :: Parsing m => m String
+symbolicOperator :: (Parsing m, MonadFail m) => m String
 symbolicOperator = do op <- token . some $ operatorLetter
                       when (op `elem` (invalidOperators ++ commentMarkers)) $
                            fail $ op ++ " is not a valid operator"
