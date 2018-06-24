$NetBSD: patch-src_main.cc,v 1.1 2018/06/24 16:59:52 adam Exp $

Fix handling of command line options.

--- src/main.cc.orig	2018-06-07 04:25:26.000000000 +0000
+++ src/main.cc
@@ -441,8 +441,6 @@ main(int argc, char** argv) {
     }
 #endif
 
-    int firstArg = parse_options(argc, argv);
-
     if (OptionParser::has_flag('n', argc, argv)) {
       lt_log_print(torrent::LOG_WARN, "Ignoring rtorrent.rc.");
     } else {
@@ -459,6 +457,8 @@ main(int argc, char** argv) {
       }
     }
 
+    int firstArg = parse_options(argc, argv);
+
     control->initialize();
 
     // Load session torrents and perform scheduled tasks to ensure
