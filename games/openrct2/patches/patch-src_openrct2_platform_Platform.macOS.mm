$NetBSD: patch-src_openrct2_platform_Platform.macOS.mm,v 1.1 2023/07/23 21:15:43 triaxx Exp $

Support pkgsrc.

--- src/openrct2/platform/Platform.macOS.mm.orig	2020-08-15 19:13:50.000000000 +0000
+++ src/openrct2/platform/Platform.macOS.mm
@@ -73,18 +73,7 @@ namespace Platform
         }
         else
         {
-            auto exePath = GetCurrentExecutablePath();
-            auto exeDirectory = Path::GetDirectory(exePath);
-            path = Path::Combine(exeDirectory, "data");
-            NSString* nsPath = [NSString stringWithUTF8String:path.c_str()];
-            if (![[NSFileManager defaultManager] fileExistsAtPath:nsPath])
-            {
-                path = GetBundlePath();
-                if (path.empty())
-                {
-                    path = "/";
-                }
-            }
+            path = "@PREFIX@/share/openrct2";
         }
         return path;
     }
