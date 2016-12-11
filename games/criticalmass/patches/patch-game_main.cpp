$NetBSD: patch-game_main.cpp,v 1.1.44.1 2016/12/11 20:47:09 spz Exp $

Add missing include (uncovered by png-1.5).
Disable online update by default.

--- game/main.cpp.orig	2006-06-30 03:46:11.000000000 +0000
+++ game/main.cpp
@@ -24,17 +24,18 @@
 #include <ResourceManager.hpp>
 #include <GetDataPath.hpp>
 #include <OnlineUpdate.hpp>
+#include <zlib.h>
 
 #include <sys/stat.h>
 #include <sys/types.h>
 
 void migrateConfig( void)
 {
-    //if onlineCheck is not set, default it to true
+    //if onlineCheck is not set, default it to false
     bool dummy;
     if( ! ConfigS::instance()->getBoolean( "onlineCheck", dummy))
     {
-	ConfigS::instance()->updateKeyword( "onlineCheck", "1");
+	ConfigS::instance()->updateKeyword( "onlineCheck", "0");
     }
 
 #ifdef WIN32
