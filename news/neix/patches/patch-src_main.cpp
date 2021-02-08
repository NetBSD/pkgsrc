$NetBSD: patch-src_main.cpp,v 1.2 2021/02/08 02:56:19 gutteridge Exp $

Consistently determine the user's configuration path at runtime, don't use a
hard-coded value that was defined as the build environment's $HOME.
https://github.com/tomschwarz/neix/pull/19

--- src/main.cpp.orig	2020-09-07 19:55:08.000000000 +0000
+++ src/main.cpp
@@ -35,7 +35,7 @@ void processArguments(int argc, char **a
 
             case 'i':
                 cout << prefix << "Import feeds from: " << optarg << endl;
-                imported = opml::import(optarg, FEED_CONFIG_PATH);
+                imported = opml::import(optarg, getFeedConfigPath());
                 cout << prefix << imported << " feed(s) was imported" << endl;
                 break;
 
