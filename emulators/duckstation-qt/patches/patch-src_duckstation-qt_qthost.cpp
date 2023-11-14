$NetBSD: patch-src_duckstation-qt_qthost.cpp,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/duckstation-qt/qthost.cpp.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/duckstation-qt/qthost.cpp
@@ -240,13 +240,7 @@ void QtHost::SetAppRoot()
 
 void QtHost::SetResourcesDirectory()
 {
-#ifndef __APPLE__
-  // On Windows/Linux, these are in the binary directory.
-  EmuFolders::Resources = Path::Combine(EmuFolders::AppRoot, "resources");
-#else
-  // On macOS, this is in the bundle resources directory.
-  EmuFolders::Resources = Path::Canonicalize(Path::Combine(EmuFolders::AppRoot, "../Resources"));
-#endif
+  EmuFolders::Resources = "@PREFIX@/share/duckstation";
 }
 
 void QtHost::SetDataDirectory()
@@ -270,7 +264,12 @@ void QtHost::SetDataDirectory()
       EmuFolders::DataRoot = Path::Combine(StringUtil::WideStringToUTF8String(documents_directory), "DuckStation");
     CoTaskMemFree(documents_directory);
   }
-#elif defined(__linux__)
+#elif defined(__APPLE__)
+  static constexpr char MAC_DATA_DIR[] = "Library/Application Support/DuckStation";
+  const char* home_dir = getenv("HOME");
+  if (home_dir)
+    EmuFolders::DataRoot = Path::Combine(home_dir, MAC_DATA_DIR);
+#else
   // Use $XDG_CONFIG_HOME/duckstation if it exists.
   const char* xdg_config_home = getenv("XDG_CONFIG_HOME");
   if (xdg_config_home && Path::IsAbsolute(xdg_config_home))
@@ -291,11 +290,6 @@ void QtHost::SetDataDirectory()
       EmuFolders::DataRoot = Path::Combine(share_dir, "duckstation");
     }
   }
-#elif defined(__APPLE__)
-  static constexpr char MAC_DATA_DIR[] = "Library/Application Support/DuckStation";
-  const char* home_dir = getenv("HOME");
-  if (home_dir)
-    EmuFolders::DataRoot = Path::Combine(home_dir, MAC_DATA_DIR);
 #endif
 
   // make sure it exists
