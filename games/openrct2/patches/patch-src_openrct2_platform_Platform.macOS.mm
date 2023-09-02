$NetBSD: patch-src_openrct2_platform_Platform.macOS.mm,v 1.3 2023/09/02 07:30:35 triaxx Exp $

Support pkgsrc.

--- src/openrct2/platform/Platform.macOS.mm.orig	2021-03-13 11:17:05.000000000 +0000
+++ src/openrct2/platform/Platform.macOS.mm
@@ -94,21 +94,7 @@ namespace Platform
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
