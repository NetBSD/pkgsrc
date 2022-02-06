$NetBSD: patch-utils_haddock_driver_Main.hs,v 1.1 2022/02/06 05:36:16 pho Exp $

Workaround for haddock dying when the locale isn't "*.UTF-8". Of course
this isn't a real fix. Haddock is very fragile when it comes to locale
setting, and fixing it properly would be seriously a lot of work.

--- utils/haddock/driver/Main.hs.orig	2020-07-28 17:05:24.000000000 +0000
+++ utils/haddock/driver/Main.hs
@@ -1,7 +1,9 @@
 module Main where
 
 import Documentation.Haddock (haddock)
+import GHC.IO.Encoding (setLocaleEncoding, utf8)
 import GHC.ResponseFile (getArgsWithResponseFiles)
 
 main :: IO ()
-main = getArgsWithResponseFiles >>= haddock
+main = do setLocaleEncoding utf8
+          getArgsWithResponseFiles >>= haddock
