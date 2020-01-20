$NetBSD: patch-src_Idris_Parser_Data.hs,v 1.1 2020/01/20 23:32:38 pho Exp $

Fix build with GHC 8.8

--- src/Idris/Parser/Data.hs.orig	2020-01-20 13:54:48.815991101 +0000
+++ src/Idris/Parser/Data.hs
@@ -91,7 +91,7 @@ record syn = (appExtent $ do
                         Nothing    -> Nothing
             return $ map (\n -> (n, p, t, doc')) ns
 
-        constructor :: (Parsing m, MonadState IState m) => m Name
+        constructor :: (Parsing m, MonadState IState m, MonadFail m) => m Name
         constructor = keyword "constructor" *> fnName
 
         endPlicity :: Maybe Char -> IdrisParser Plicity
