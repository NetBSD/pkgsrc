$NetBSD: patch-src_main.cpp,v 1.1 2021/02/07 05:06:12 gutteridge Exp $

Consistently determine the user's configuration path at runtime, don't use a
hard-coded value that was defined as the build environment's $HOME.

--- src/main.cpp.orig	2020-09-07 19:55:08.000000000 +0000
+++ src/main.cpp
@@ -35,7 +35,7 @@ void processArguments(int argc, char **a
 
             case 'i':
                 cout << prefix << "Import feeds from: " << optarg << endl;
-                imported = opml::import(optarg, FEED_CONFIG_PATH);
+                imported = opml::import(optarg, getFeedConfigPath());
                 cout << prefix << imported << " feed(s) was imported" << endl;
                 break;
 
