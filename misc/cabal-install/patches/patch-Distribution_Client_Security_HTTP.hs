$NetBSD: patch-Distribution_Client_Security_HTTP.hs,v 1.1 2020/01/19 07:51:26 pho Exp $

Fix build with hackage-security-0.6:
https://github.com/haskell/cabal/commit/0165f0a739a634ed03e6c87f258ebb5810005d21

--- Distribution/Client/Security/HTTP.hs.orig	2001-09-09 01:46:40.000000000 +0000
+++ Distribution/Client/Security/HTTP.hs
@@ -35,7 +35,6 @@ import Hackage.Security.Client
 import Hackage.Security.Client.Repository.HttpLib
 import Hackage.Security.Util.Checked
 import Hackage.Security.Util.Pretty
-import qualified Hackage.Security.Util.Lens as Lens
 
 {-------------------------------------------------------------------------------
   'HttpLib' implementation
@@ -142,7 +141,14 @@ mkReqHeaders reqHeaders mRange = concat 
     finalize (name, strs) = [HTTP.Header name (intercalate ", " (reverse strs))]
 
     insert :: Eq a => a -> [b] -> [(a, [b])] -> [(a, [b])]
-    insert x y = Lens.modify (Lens.lookupM x) (++ y)
+    insert x y = modifyAssocList x (++ y)
+
+    -- modify the first matching element
+    modifyAssocList :: Eq a => a -> (b -> b) -> [(a, b)] -> [(a, b)]
+    modifyAssocList a f = go where
+        go []                         = []
+        go (p@(a', b) : xs) | a == a'   = (a', f b) : xs
+                            | otherwise = p         : go xs
 
 {-------------------------------------------------------------------------------
   Custom exceptions
