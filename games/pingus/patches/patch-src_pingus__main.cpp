$NetBSD: patch-src_pingus__main.cpp,v 1.1 2012/11/23 12:35:01 joerg Exp $

--- src/pingus_main.cpp.orig	2012-11-22 20:46:56.000000000 +0000
+++ src/pingus_main.cpp
@@ -626,7 +626,7 @@ PingusMain::init_path_finder()
 void
 PingusMain::print_greeting_message()
 {
-  std::string greeting = "Welcome to Pingus "VERSION;
+  std::string greeting = "Welcome to Pingus " VERSION;
   greeting += "!";
   std::cout <<  greeting << std::endl;
   for (unsigned int i = 0; i < greeting.length(); ++i)
