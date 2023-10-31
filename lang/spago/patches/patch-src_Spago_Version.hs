$NetBSD: patch-src_Spago_Version.hs,v 1.1 2023/10/31 12:21:13 pho Exp $

Fix build with versions-6.0.

--- src/Spago/Version.hs.orig	2023-10-31 12:11:08.160531352 +0000
+++ src/Spago/Version.hs
@@ -60,19 +60,22 @@ getCurrentVersion = do
 
   case Safe.maximumMay tags of
     Nothing -> do
-      logInfo $ display $ "No git version tags found, so assuming current version is " <> unparseVersion mempty
-      pure mempty
+      logInfo $ display $ "No git version tags found, so assuming current version is " <> unparseVersion semVerZero
+      pure semVerZero
     Just maxVersion -> do
       logInfo $ display $ "Found current version from git tag: " <> unparseVersion maxVersion
       pure maxVersion
+  where
+    semVerZero :: SemVer
+    semVerZero = SemVer 0 0 0 Nothing Nothing
 
 
 getNextVersion :: VersionBump -> SemVer -> Either Text SemVer
 getNextVersion spec currentV@SemVer{..} =
   case spec of
-    Major -> Right $ SemVer (_svMajor + 1) 0 0 [] mempty
-    Minor -> Right $ SemVer _svMajor (_svMinor + 1) 0 [] mempty
-    Patch -> Right $ SemVer _svMajor _svMinor (_svPatch + 1) [] mempty
+    Major -> Right $ SemVer (_svMajor + 1) 0 0 Nothing Nothing
+    Minor -> Right $ SemVer _svMajor (_svMinor + 1) 0 Nothing Nothing
+    Patch -> Right $ SemVer _svMajor _svMinor (_svPatch + 1) Nothing Nothing
     Exact newV
       | currentV < newV -> Right newV
       | otherwise -> do
