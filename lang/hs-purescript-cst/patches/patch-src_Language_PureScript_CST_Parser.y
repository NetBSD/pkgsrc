$NetBSD: patch-src_Language_PureScript_CST_Parser.y,v 1.1 2022/02/23 16:19:45 pho Exp $

Fix build with GHC 9.0; broken due to this change:
https://github.com/ghc-proposals/ghc-proposals/blob/master/proposals/0287-simplify-subsumption.rst

--- src/Language/PureScript/CST/Parser.y.orig	2022-02-20 15:02:26.193617354 +0000
+++ src/Language/PureScript/CST/Parser.y
@@ -639,7 +639,7 @@ export :: { Export () }
 dataMembers :: { (DataMembers ()) }
  : '(..)' { DataAll () $1 }
  | '(' ')' { DataEnumerated () (Wrapped $1 Nothing $2) }
- | '(' sep(properName, ',') ')' { DataEnumerated () (Wrapped $1 (Just \$ getProperName <\$> $2) $3) }
+ | '(' sep(properName, ',') ')' { DataEnumerated () (Wrapped $1 (Just \$ (\pn -> getProperName pn) <\$> $2) $3) }
 
 importDecl :: { ImportDecl () }
   : 'import' moduleName imports { ImportDecl () $1 $2 $3 Nothing }
