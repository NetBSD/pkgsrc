$NetBSD: patch-src_duckstation-nogui_nogui__host.cpp,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/duckstation-nogui/nogui_host.cpp.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/duckstation-nogui/nogui_host.cpp
@@ -183,7 +183,12 @@ void NoGUIHost::SetDataDirectory()
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
@@ -204,11 +209,6 @@ void NoGUIHost::SetDataDirectory()
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
