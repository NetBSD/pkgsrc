$NetBSD: patch-src_Text_Pandoc_Options.hs,v 1.1 2021/04/25 07:50:13 pho Exp $

Fix build with GHC 9... or what version of GHC allows this? I think
TemplateHaskell has always been order-sensitive.

--- src/Text/Pandoc/Options.hs.orig	2021-04-25 04:26:58.035286453 +0000
+++ src/Text/Pandoc/Options.hs
@@ -316,6 +316,11 @@ defaultKaTeXURL :: Text
 defaultKaTeXURL = "https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.11.1/"
 
 -- Update documentation in doc/filters.md if this is changed.
+$(deriveJSON defaultOptions{ constructorTagModifier =
+                               camelCaseStrToHyphenated
+                           } ''TrackChanges)
+
+-- Update documentation in doc/filters.md if this is changed.
 $(deriveJSON defaultOptions ''ReaderOptions)
 
 $(deriveJSON defaultOptions{
@@ -339,11 +344,6 @@ $(deriveJSON defaultOptions{ constructor
 
 $(deriveJSON defaultOptions ''HTMLSlideVariant)
 
--- Update documentation in doc/filters.md if this is changed.
-$(deriveJSON defaultOptions{ constructorTagModifier =
-                               camelCaseStrToHyphenated
-                           } ''TrackChanges)
-
 $(deriveJSON defaultOptions{ constructorTagModifier =
                                camelCaseStrToHyphenated
                            } ''WrapOption)
