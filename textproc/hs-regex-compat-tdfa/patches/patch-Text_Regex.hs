$NetBSD: patch-Text_Regex.hs,v 1.1 2022/02/14 14:42:57 pho Exp $

Fix build with GHC 9.2

--- Text/Regex.hs.orig	2022-02-14 13:00:42.545834464 +0000
+++ Text/Regex.hs
@@ -139,7 +139,7 @@ behavior of the the original Text.Regex 
 splitRegex :: Regex -> String -> [String]
 splitRegex _ [] = []
 splitRegex delim strIn = 
-  let matches = map (!0) (matchAll delim strIn)
+  let matches = map (! 0) (matchAll delim strIn)
       go _i str [] = str : []
       go i str ((off,len):rest) =
         let i' = off+len
