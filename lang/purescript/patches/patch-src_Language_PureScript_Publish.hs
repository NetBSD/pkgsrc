$NetBSD: patch-src_Language_PureScript_Publish.hs,v 1.1 2022/02/23 16:22:33 pho Exp $

Fix build with aeson-2.0

--- src/Language/PureScript/Publish.hs.orig	2022-02-20 18:01:35.029300166 +0000
+++ src/Language/PureScript/Publish.hs
@@ -23,6 +23,7 @@ import Control.Arrow ((***))
 import Control.Category ((>>>))
 import Control.Monad.Writer.Strict (MonadWriter, WriterT, runWriterT, tell)
 
+import qualified Data.Aeson.Key as Key
 import Data.Aeson.BetterErrors (Parse, parse, keyMay, eachInObjectWithKey, key, asString, withString)
 import qualified Data.ByteString.Lazy as BL
 import Data.String (String, lines)
@@ -321,7 +322,7 @@ parseResolutionsFile resolutionsFile = d
 -- "path" field is required.
 asResolutions :: Parse D.PackageError [(PackageName, (FilePath, DependencyStatus))]
 asResolutions =
-  eachInObjectWithKey parsePackageName $
+  eachInObjectWithKey (parsePackageName . Key.toText) $
     (,) <$> key "path" asString
         <*> (maybe NoResolution ResolvedVersion <$> keyMay "version" asVersion)
 
