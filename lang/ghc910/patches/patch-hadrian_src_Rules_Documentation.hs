$NetBSD: patch-hadrian_src_Rules_Documentation.hs,v 1.1 2025/01/29 13:21:53 pho Exp $

Hunk #0, #2, #3:
    Do not assume the current locale is *.UTF-8. It isn't the case in
    pkgsrc.

    TODO: Upstream this

Hunk #1:
    This is pkgsrc-specific. ${WRKSRC}/docs/users_guide/compare-flags.py
    needs to invoke GHC we just built, which is impossible in our case
    because it has an absolute DT_RPATH to a library which hasn't been
    installed yet. But this script is only useful during the development of
    GHC so it's not worth running.

    Obviously not eligible for upstreaming.

--- hadrian/src/Rules/Documentation.hs.orig	2025-01-27 18:06:59.665271497 +0000
+++ hadrian/src/Rules/Documentation.hs
@@ -11,6 +11,7 @@ module Rules.Documentation (
 import Hadrian.BuildPath
 import Hadrian.Haskell.Cabal
 import Hadrian.Haskell.Cabal.Type
+import System.IO (IOMode(ReadMode), hGetContents', hSetEncoding, utf8, withFile)
 
 import Rules.Generate (ghcPrimDependencies)
 import Base
@@ -137,9 +138,6 @@ documentationRules = do
 
         need $ map (root -/-) targets
 
-        when (SphinxHTML `Set.member` doctargets)
-          $ checkUserGuideFlags $ root -/- htmlRoot -/- "users_guide" -/- "ghc-flags.txt"
-
     where archiveTarget "libraries"   = Haddocks
           archiveTarget _             = SphinxHTML
 
@@ -149,7 +147,7 @@ documentationRules = do
 checkSphinxWarnings :: FilePath  -- ^ output directory
                     -> Action ()
 checkSphinxWarnings out = do
-    log <- liftIO $ readFile (out -/- ".log")
+    log <- liftIO $ readUtf8File (out -/- ".log")
     when ("Inline literal start-string without end-string." `isInfixOf` log)
       $ fail $ unlines
         [ "Syntax error found in Sphinx log. "
@@ -174,6 +172,10 @@ checkSphinxWarnings out = do
     when (any hasError (lines log))
       $ fail "Errors found in the Sphinx log."
     where
+        readUtf8File path =
+            withFile path ReadMode $ \h ->
+                hSetEncoding h utf8 >> hGetContents' h
+
         hasError line =
             case words line of
                 _ : "ERROR:" : _ -> True
