$NetBSD: patch-src_Language_PureScript_Names.hs,v 1.1 2022/02/23 16:19:45 pho Exp $

Fix build with GHC 9.2

--- src/Language/PureScript/Names.hs.orig	2022-02-20 14:42:44.276703645 +0000
+++ src/Language/PureScript/Names.hs
@@ -237,9 +237,6 @@ isQualifiedWith :: ModuleName -> Qualifi
 isQualifiedWith mn (Qualified (Just mn') _) = mn == mn'
 isQualifiedWith _ _ = False
 
-$(deriveJSON (defaultOptions { sumEncoding = ObjectWithSingleField }) ''Qualified)
-$(deriveJSON (defaultOptions { sumEncoding = ObjectWithSingleField }) ''Ident)
-
 instance ToJSON ModuleName where
   toJSON (ModuleName name) = toJSON (T.splitOn "." name)
 
@@ -253,3 +250,6 @@ instance ToJSONKey ModuleName where
 
 instance FromJSONKey ModuleName where
   fromJSONKey = fmap moduleNameFromString fromJSONKey
+
+$(deriveJSON (defaultOptions { sumEncoding = ObjectWithSingleField }) ''Qualified)
+$(deriveJSON (defaultOptions { sumEncoding = ObjectWithSingleField }) ''Ident)
