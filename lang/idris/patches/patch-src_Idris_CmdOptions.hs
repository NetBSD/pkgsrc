$NetBSD: patch-src_Idris_CmdOptions.hs,v 1.1 2020/01/20 23:32:38 pho Exp $

Fix build with GHC 8.8

--- src/Idris/CmdOptions.hs.orig	2020-01-20 13:55:58.687348620 +0000
+++ src/Idris/CmdOptions.hs
@@ -264,7 +264,7 @@ parseCodegen :: String -> Codegen
 parseCodegen "bytecode" = Bytecode
 parseCodegen cg         = Via IBCFormat (map toLower cg)
 
-parseLogCats :: Monad m => String -> m [LogCat]
+parseLogCats :: MonadFail m => String -> m [LogCat]
 parseLogCats s =
     case lastMay (readP_to_S doParse s) of
       Just (xs, _) -> return xs
@@ -290,7 +290,7 @@ parseLogCats s =
       s <- look
       fail $ "Category: " ++ s ++ " is not recognised."
 
-parseConsoleWidth :: Monad m => String -> m ConsoleWidth
+parseConsoleWidth :: MonadFail m => String -> m ConsoleWidth
 parseConsoleWidth "auto"     = return AutomaticWidth
 parseConsoleWidth "infinite" = return InfinitelyWide
 parseConsoleWidth  s =
