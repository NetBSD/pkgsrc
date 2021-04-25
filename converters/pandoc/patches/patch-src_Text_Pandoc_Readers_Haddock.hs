$NetBSD: patch-src_Text_Pandoc_Readers_Haddock.hs,v 1.1 2021/04/25 07:50:13 pho Exp $

Fix build with haddock-library-1.10.0. I don't think this is a proper
fix, but let's just hope the upstream will handle this properly.

--- src/Text/Pandoc/Readers/Haddock.hs.orig	2021-04-25 04:33:58.688747948 +0000
+++ src/Text/Pandoc/Readers/Haddock.hs
@@ -129,7 +129,7 @@ docHToInlines isCode d' =
           DocIdentifier s -> B.codeWith ("",["haskell","identifier"],[]) $ T.pack s
           _               -> mempty
     DocIdentifierUnchecked s -> B.codeWith ("",["haskell","identifier"],[]) $ T.pack s
-    DocModule s -> B.codeWith ("",["haskell","module"],[]) $ T.pack s
+    DocModule (ModLink s _) -> B.codeWith ("",["haskell","module"],[]) $ T.pack s
     DocWarning _ -> mempty -- TODO
     DocEmphasis d -> B.emph (docHToInlines isCode d)
     DocMonospaced (DocString s) -> B.code $ T.pack s
