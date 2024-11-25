$NetBSD: patch-src_openrct2_platform_Platform.macOS.mm,v 1.6 2024/11/25 22:06:30 triaxx Exp $

Support pkgsrc.

--- src/openrct2/platform/Platform.macOS.mm.orig	2024-11-03 17:41:19.000000000 +0000
+++ src/openrct2/platform/Platform.macOS.mm
@@ -75,7 +75,7 @@ namespace OpenRCT2::Platform
 
     std::string GetDocsPath()
     {
-        return GetBundlePath();
+        return "@PREFIX@/share/doc/openrct2";
     }
 
     std::string GetInstallPath()
@@ -96,22 +96,7 @@ namespace OpenRCT2::Platform
             }
             else
             {
-                // this is not in an app bundle
-                auto exePath = GetCurrentExecutablePath();
-                auto exeDirectory = Path::GetDirectory(exePath);
-
-                // check build and install paths
-                NSArray* dataSearchLocations = @[ @"data", @"../share/openrct2" ];
-
-                for (NSString* searchLocation in dataSearchLocations)
-                {
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
