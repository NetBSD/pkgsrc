$NetBSD: patch-utils_genprimopcode_Main.hs,v 1.2 2023/11/02 14:32:04 pho Exp $

primops.txt contains Unicode characters. Don't assume the current locale is
"*.UTF-8".

> LC_ALL=C ./genprimopcode --data-decl < ./primops.txt
> genprimopcode: <stdin>: hGetContents: invalid argument (cannot decode byte sequence starting from 226)

https://gitlab.haskell.org/ghc/ghc/-/merge_requests/11544

--- utils/genprimopcode/Main.hs.orig	2023-10-23 03:34:51.628735818 +0000
+++ utils/genprimopcode/Main.hs
@@ -13,6 +13,7 @@ import Data.Char
 import Data.List (union, intersperse, intercalate, nub)
 import Data.Maybe ( catMaybes )
 import System.Environment ( getArgs )
+import System.IO ( hGetContents, hSetEncoding, stdin, utf8 )
 
 vecOptions :: Entry -> [(String,String,Int)]
 vecOptions i =
@@ -116,7 +117,9 @@ main = getArgs >>= \args ->
                    ++ unlines (map ("            "++) known_args)
                   )
        else
-       do s <- getContents
+       do let input = stdin
+          hSetEncoding input utf8
+          s <- hGetContents input
           case parse s of
              Left err -> error ("parse error at " ++ (show err))
              Right p_o_specs@(Info _ _)
