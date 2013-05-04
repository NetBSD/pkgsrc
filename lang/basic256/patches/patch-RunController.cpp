$NetBSD: patch-RunController.cpp,v 1.1 2013/05/04 12:48:33 joerg Exp $

Avoid overlap with std::mutex.

--- RunController.cpp.orig	2013-05-04 00:27:12.000000000 +0000
+++ RunController.cpp
@@ -80,6 +80,7 @@ using namespace std;
 	#define SDL_CHAN_SOUND 2
 #endif
 
+#define mutex my_mutex
 QMutex mutex;
 QMutex debugmutex;
 QWaitCondition waitCond;
