$NetBSD: patch-app_Main.hs,v 1.1 2022/02/23 16:22:33 pho Exp $

Fix build with optparse-applicative-0.17

--- app/Main.hs.orig	2022-02-20 19:11:59.577636859 +0000
+++ app/Main.hs
@@ -48,7 +48,7 @@ main = do
     -- | Displays full command help when invoked with no arguments.
     execParserPure :: Opts.ParserInfo a -> [String] -> Opts.ParserResult a
     execParserPure pinfo [] = Opts.Failure $
-      Opts.parserFailure Opts.defaultPrefs pinfo Opts.ShowHelpText mempty
+      Opts.parserFailure Opts.defaultPrefs pinfo (Opts.ShowHelpText Nothing) mempty
     execParserPure pinfo args = Opts.execParserPure Opts.defaultPrefs pinfo args
 
     versionInfo :: Opts.Parser (a -> a)
