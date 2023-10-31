$NetBSD: patch-Aws_DynamoDb_Core.hs,v 1.1 2023/10/31 11:26:02 pho Exp $

Fix build with aeson-2.2.

--- Aws/DynamoDb/Core.hs.orig	2023-10-31 11:14:52.251573057 +0000
+++ Aws/DynamoDb/Core.hs
@@ -130,6 +130,7 @@ import           Data.Aeson
 import qualified Data.Aeson                   as A
 import qualified Data.Aeson.Key               as AK
 import qualified Data.Aeson.KeyMap            as KM
+import qualified Data.Aeson.Parser            as A
 import           Data.Aeson.Types             (Pair, parseEither)
 import qualified Data.Aeson.Types             as A
 import qualified Data.Attoparsec.ByteString   as AttoB (endOfInput)
@@ -1164,7 +1165,7 @@ data QuerySelect
 instance Default QuerySelect where def = SelectAll
 
 -------------------------------------------------------------------------------
-querySelectJson :: KeyValue t => QuerySelect -> [t]
+querySelectJson :: KeyValue e t => QuerySelect -> [t]
 querySelectJson (SelectSpecific as) =
     [ "Select" .= String "SPECIFIC_ATTRIBUTES"
     , "AttributesToGet" .= as]
