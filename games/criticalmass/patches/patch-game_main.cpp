$NetBSD: patch-game_main.cpp,v 1.1 2011/06/20 09:30:03 wiz Exp $

Add missing include (uncovered by png-1.5).

--- game/main.cpp.orig	2006-06-30 03:46:11.000000000 +0000
+++ game/main.cpp
@@ -24,6 +24,7 @@
 #include <ResourceManager.hpp>
 #include <GetDataPath.hpp>
 #include <OnlineUpdate.hpp>
+#include <zlib.h>
 
 #include <sys/stat.h>
 #include <sys/types.h>
