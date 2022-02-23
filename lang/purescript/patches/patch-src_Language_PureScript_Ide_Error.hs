$NetBSD: patch-src_Language_PureScript_Ide_Error.hs,v 1.1 2022/02/23 16:22:33 pho Exp $

Fix build with aeson-2.0

--- src/Language/PureScript/Ide/Error.hs.orig	2022-02-20 18:04:21.957211592 +0000
+++ src/Language/PureScript/Ide/Error.hs
@@ -19,7 +19,7 @@ module Language.PureScript.Ide.Error
 
 import           Data.Aeson
 import qualified Data.Aeson.Types as Aeson
-import qualified Data.HashMap.Lazy as HM
+import qualified Data.Aeson.KeyMap as KM
 import qualified Data.Text as T
 import qualified Language.PureScript as P
 import           Language.PureScript.Errors.JSON
@@ -59,7 +59,7 @@ encodeRebuildErrors = toJSON . map encod
 
     insertTSCompletions name idents fields (Aeson.Object value) =
       Aeson.Object
-        (HM.insert "pursIde"
+        (KM.insert "pursIde"
          (object [ "name" .= name
                  , "completions" .= ordNub (map identCompletion idents ++ map fieldCompletion fields)
                  ]) value)
