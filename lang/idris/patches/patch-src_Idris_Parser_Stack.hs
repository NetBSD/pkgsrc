$NetBSD: patch-src_Idris_Parser_Stack.hs,v 1.1 2020/01/20 23:32:38 pho Exp $

Fix build with recent megaparsec.

--- src/Idris/Parser/Stack.hs.orig	2020-01-20 13:28:28.122727647 +0000
+++ src/Idris/Parser/Stack.hs
@@ -76,11 +76,12 @@ parseErrorOffset = P.errorOffset . parse
 instance Message ParseError where
   messageExtent err = sourcePositionFC pos
     where
-      (pos, _) = P.reachOffsetNoLine (parseErrorOffset err) (parseErrorPosState err)
+      pos = P.pstateSourcePos $
+            P.reachOffsetNoLine (parseErrorOffset err) (parseErrorPosState err)
   messageText = PP.text . init . P.parseErrorTextPretty . parseError
   messageSource err = Just sline
     where
-      (_, sline, _) = P.reachOffset (parseErrorOffset err) (parseErrorPosState err)
+      (sline, _) = P.reachOffset (parseErrorOffset err) (parseErrorPosState err)
 
 -- | A fully formatted parse error, with caret and bar, etc.
 prettyError :: ParseError -> String
@@ -88,7 +89,7 @@ prettyError =  P.errorBundlePretty . unP
 
 {- * Mark and restore -}
 
-type Mark = P.State String
+type Mark = P.State String Void
 
 -- | Retrieve the parser state so we can restart from this point later.
 mark :: Parsing m => m Mark
