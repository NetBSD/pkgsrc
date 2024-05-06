$NetBSD: patch-source_src_server.cpp,v 1.1 2024/05/06 17:30:50 nia Exp $

C++98 compliance.

--- source/src/server.cpp.orig	2024-05-06 16:25:52.000000000 +0000
+++ source/src/server.cpp
@@ -25,7 +25,7 @@ struct servergame
     string servdesc_current;
     ENetAddress servdesc_caller;
     bool custom_servdesc;
-    int sispaused = 0;
+    int sispaused;
 
     // current game
     string smapname, nextmapname;
@@ -52,6 +52,7 @@ struct servergame
         matchteamsize = 0;
         forceintermission = false;
         custom_servdesc = false;
+        sispaused = 0;
         smode = 0;
         interm = 0;
         minremain = 0;
