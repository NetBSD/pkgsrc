$NetBSD: patch-src_Spago_Bower.hs,v 1.1 2022/02/24 01:27:40 pho Exp $

Fix build with aeson-2.0

--- src/Spago/Bower.hs.orig	2022-02-21 10:02:11.595064997 +0000
+++ src/Spago/Bower.hs
@@ -9,7 +9,7 @@ import Spago.Env
 
 import qualified Data.Aeson                 as Aeson
 import qualified Data.Aeson.Encode.Pretty   as Pretty
-import qualified Data.HashMap.Strict        as HashMap
+import qualified Data.Aeson.KeyMap          as KeyMap
 import qualified Data.Text                  as Text
 import qualified System.Info
 import qualified Turtle
@@ -109,7 +109,7 @@ mkBowerVersion packageName version (Repo
       Just (Object obj) -> pure obj
       _ -> die [ display $ "Unable to decode output from `bower " <> Text.intercalate " " args <> "`: ", display out ]
 
-    if HashMap.member "version" info
+    if KeyMap.member "version" info
       then pure $ Bower.VersionRange $ "^" <> version
       else pure $ Bower.VersionRange $ repo <> "#" <> version
 
