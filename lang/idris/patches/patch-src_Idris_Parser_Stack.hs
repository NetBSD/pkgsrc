$NetBSD: patch-src_Idris_Parser_Stack.hs,v 1.2 2021/04/25 11:39:03 pho Exp $

Fix build with megaparsec-9.0.*.

--- src/Idris/Parser/Stack.hs.orig	2021-04-25 10:29:33.784393017 +0000
+++ src/Idris/Parser/Stack.hs
@@ -84,7 +84,7 @@ instance Message ParseError where
       (pos, _) = P.reachOffsetNoLine (parseErrorOffset err) (parseErrorPosState err)
 #endif
   messageText = PP.text . init . P.parseErrorTextPretty . parseError
-  messageSource err = Just sline
+  messageSource err = sline
     where
 #if MIN_VERSION_megaparsec(8,0,0)
       (sline, _) = P.reachOffset (parseErrorOffset err) (parseErrorPosState err)
