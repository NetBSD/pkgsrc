$NetBSD: patch-src_Idris_Parser_Helpers.hs,v 1.1 2020/01/20 23:32:38 pho Exp $

Fix build with GHC 8.8

--- src/Idris/Parser/Helpers.hs.orig	2020-01-20 13:35:28.654072395 +0000
+++ src/Idris/Parser/Helpers.hs
@@ -512,7 +512,7 @@ notEndBlock = do ist <- get
                                           when (i < lvl || isParen) (fail "end of block")
                       _ -> return ()
 
-indentGt :: (Parsing m, MonadState IState m) => m ()
+indentGt :: (Parsing m, MonadState IState m, MonadFail m) => m ()
 indentGt = do
   li <- lastIndent
   i <- indent
