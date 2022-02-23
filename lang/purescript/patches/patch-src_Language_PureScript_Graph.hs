$NetBSD: patch-src_Language_PureScript_Graph.hs,v 1.1 2022/02/23 16:22:33 pho Exp $

Fix build with aeson-2.0

--- src/Language/PureScript/Graph.hs.orig	2022-02-20 17:59:47.559345082 +0000
+++ src/Language/PureScript/Graph.hs
@@ -3,7 +3,8 @@ module Language.PureScript.Graph (graph)
 import Prelude.Compat
 
 import qualified Data.Aeson as Json
-import qualified Data.HashMap.Strict as HashMap
+import qualified Data.Aeson.Key as Key
+import qualified Data.Aeson.KeyMap as KeyMap
 import qualified Data.Map as Map
 
 import           Control.Monad (forM)
@@ -44,7 +45,7 @@ moduleGraphToJSON
 moduleGraphToJSON paths = Json.Object . foldl' insert mempty
   where
   insert :: Json.Object -> (ModuleName, [ModuleName]) -> Json.Object
-  insert obj (mn, depends) = HashMap.insert (runModuleName mn) value obj
+  insert obj (mn, depends) = KeyMap.insert (Key.fromText $ runModuleName mn) value obj
     where
       path = fromMaybe (Crash.internalError "missing module name in graph") $ Map.lookup mn paths
       value = Json.object
