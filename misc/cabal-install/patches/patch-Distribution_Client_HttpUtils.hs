$NetBSD: patch-Distribution_Client_HttpUtils.hs,v 1.1 2021/04/25 13:43:44 pho Exp $

Fix build with base16-bytestring-1.0.*

--- Distribution/Client/HttpUtils.hs.orig	2021-04-25 13:14:42.533821044 +0000
+++ Distribution/Client/HttpUtils.hs
@@ -182,7 +182,9 @@ downloadURI transport verbosity uri path
     fragmentParser = do
         _ <- P.string "#sha256="
         str <- some P.hexDigit
-        return (fst (Base16.decode (BS8.pack str)))
+        case Base16.decode (BS8.pack str) of
+            Right b16 -> return b16
+            Left err  -> fail err
 
 ------------------------------------------------------------------------------
 -- Utilities for repo url management
