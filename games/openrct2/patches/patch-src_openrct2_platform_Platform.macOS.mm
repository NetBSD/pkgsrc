$NetBSD: patch-src_openrct2_platform_Platform.macOS.mm,v 1.5 2024/01/04 21:37:29 triaxx Exp $

Support pkgsrc.

--- src/openrct2/platform/Platform.macOS.mm.orig	2023-12-31 14:09:59.000000000 +0000
+++ src/openrct2/platform/Platform.macOS.mm
@@ -75,7 +75,7 @@ namespace Platform
 
     std::string GetDocsPath()
     {
-        return GetBundlePath();
+        return "@PREFIX@/share/doc/openrct2";
     }
 
     std::string GetInstallPath()
@@ -96,21 +96,7 @@ namespace Platform
             }
             else
             {
-                // this is not in an app bundle
-                auto exePath = GetCurrentExecutablePath();
-                auto exeDirectory = Path::GetDirectory(exePath);
-
-                // check build and install paths
-                NSArray *dataSearchLocations = @[@"data", @"../share/openrct2"];
-
-                for (NSString *searchLocation in dataSearchLocations) {
-                    path = Path::Combine(exeDirectory, [searchLocation UTF8String]);
-                    NSString* nsPath = [NSString stringWithUTF8String:path.c_str()];
-                    if ([[NSFileManager defaultManager] fileExistsAtPath:nsPath])
-                    {
-                        return path;
-                    }
-                }
+                return "@PREFIX@/share/openrct2";
             }
         }
         return "/";
