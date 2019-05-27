$NetBSD: patch-src_pingus_pingus__main.cpp,v 1.2 2019/05/27 16:07:30 maya Exp $

* Set DATADIR according to pkgsrc (program is not launched from source dir).
* Insert space to appease C++11.

--- src/pingus/pingus_main.cpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/pingus/pingus_main.cpp
@@ -441,20 +441,8 @@ PingusMain::init_path_finder()
     g_path_manager.set_path(cmd_options.datadir.get());
   }
   else
-  { // do magic to guess the datadir
-#if defined(__APPLE__)
-    char resource_path[PATH_MAX];
-    CFURLRef ref = CFBundleCopyResourcesDirectoryURL(CFBundleGetMainBundle());
-    if (!ref || !CFURLGetFileSystemRepresentation(ref, true, (UInt8*)resource_path, PATH_MAX))
-    {
-      std::cout << "Error: Couldn't get Resources path.\n" << std::endl;
-      exit(EXIT_FAILURE);
-    }
-    CFRelease(ref);
-    g_path_manager.set_path("data");
-#else
-    g_path_manager.set_path("data"); // assume game is run from source dir
-#endif
+  {
+    g_path_manager.set_path("@DATADIR@"); // assume game is run from source dir
   }
 
   // Language is automatically picked from env variable
@@ -465,7 +453,7 @@ PingusMain::init_path_finder()
 void
 PingusMain::print_greeting_message()
 {
-  std::string greeting = "Welcome to Pingus "VERSION;
+  std::string greeting = "Welcome to Pingus " VERSION;
   greeting += "!";
   std::cout <<  greeting << std::endl;
   for (unsigned int i = 0; i < greeting.length(); ++i)
