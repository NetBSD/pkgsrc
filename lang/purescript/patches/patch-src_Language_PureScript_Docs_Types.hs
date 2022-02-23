$NetBSD: patch-src_Language_PureScript_Docs_Types.hs,v 1.1 2022/02/23 16:22:33 pho Exp $

Fix build with aeson-2.0

--- src/Language/PureScript/Docs/Types.hs.orig	2022-02-20 17:30:25.395973220 +0000
+++ src/Language/PureScript/Docs/Types.hs
@@ -20,6 +20,7 @@ import Data.Time.Clock (UTCTime)
 import qualified Data.Time.Format as TimeFormat
 import Data.Version
 import qualified Data.Aeson as A
+import qualified Data.Aeson.Key as Key
 import qualified Data.Text as T
 import qualified Data.Vector as V
 
@@ -702,7 +703,7 @@ asQualifiedProperName = fromAesonParser
 asModuleMap :: Parse PackageError (Map P.ModuleName PackageName)
 asModuleMap =
   Map.fromList <$>
-    eachInObjectWithKey (Right . P.moduleNameFromString)
+    eachInObjectWithKey (Right . P.moduleNameFromString . Key.toText)
                         (withText parsePackageName')
 
 -- This is here to preserve backwards compatibility with compilers which used
@@ -722,7 +723,7 @@ bookmarksAsModuleMap =
 
 asResolvedDependencies :: Parse PackageError [(PackageName, Version)]
 asResolvedDependencies =
-  eachInObjectWithKey parsePackageName' asVersion
+  eachInObjectWithKey (parsePackageName' . Key.toText) asVersion
 
 parsePackageName' :: Text -> Either PackageError PackageName
 parsePackageName' =
@@ -751,10 +752,10 @@ instance A.ToJSON a => A.ToJSON (Package
       , "version"              .= showVersion pkgVersion
       , "versionTag"           .= pkgVersionTag
       , "modules"              .= pkgModules
-      , "moduleMap"            .= assocListToJSON P.runModuleName
+      , "moduleMap"            .= assocListToJSON (Key.fromText . P.runModuleName)
                                                   runPackageName
                                                   (Map.toList pkgModuleMap)
-      , "resolvedDependencies" .= assocListToJSON runPackageName
+      , "resolvedDependencies" .= assocListToJSON (Key.fromText . runPackageName)
                                                   (T.pack . showVersion)
                                                   pkgResolvedDependencies
       , "github"               .= pkgGithub
@@ -840,7 +841,7 @@ instance A.ToJSON GithubRepo where
 --
 -- For example:
 -- @assocListToJSON T.pack T.pack [("a", "b")]@ will give @{"a": "b"}@.
-assocListToJSON :: (a -> Text) -> (b -> Text) -> [(a, b)] -> A.Value
+assocListToJSON :: (a -> A.Key) -> (b -> Text) -> [(a, b)] -> A.Value
 assocListToJSON f g xs = A.object (map (uncurry (.=) . (f *** g)) xs)
 
 instance A.ToJSON a => A.ToJSON (InPackage a) where
