$NetBSD: patch-src_Language_LSP_Protocol_Types_Common.hs,v 1.1 2023/10/31 04:01:39 pho Exp $

Fix build with aeson-2.2

--- src/Language/LSP/Protocol/Types/Common.hs.orig	2023-10-31 03:52:25.874104652 +0000
+++ src/Language/LSP/Protocol/Types/Common.hs
@@ -175,7 +175,7 @@ instance Semigroup s => Semigroup (s |? 
   -- We use String so we can use fromString on it to get a key that works
   -- in both aeson-1 and aeson-2
 -- | Include a value in an JSON object optionally, omitting it if it is 'Nothing'.
-(.=?) :: (J.KeyValue kv, J.ToJSON v) => String -> Maybe v -> [kv]
+(.=?) :: (J.KeyValue e kv, J.ToJSON v) => String -> Maybe v -> [kv]
 k .=? v = case v of
   Just v' -> [fromString k J..= v']
   Nothing -> mempty
