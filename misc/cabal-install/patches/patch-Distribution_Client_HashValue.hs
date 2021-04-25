$NetBSD: patch-Distribution_Client_HashValue.hs,v 1.1 2021/04/25 13:43:44 pho Exp $

Fix build with base16-bytestring-1.0.*

--- Distribution/Client/HashValue.hs.orig	2021-04-25 13:09:32.521615949 +0000
+++ Distribution/Client/HashValue.hs
@@ -71,9 +71,8 @@ hashFromTUF (Sec.Hash hashstr) =
     --TODO: [code cleanup] either we should get TUF to use raw bytestrings or
     -- perhaps we should also just use a base16 string as the internal rep.
     case Base16.decode (BS.pack hashstr) of
-      (hash, trailing) | not (BS.null hash) && BS.null trailing
-        -> HashValue hash
-      _ -> error "hashFromTUF: cannot decode base16 hash"
+      Right hash -> HashValue hash
+      Left  _    -> error "hashFromTUF: cannot decode base16 hash"
 
 
 -- | Truncate a 32 byte SHA256 hash to
