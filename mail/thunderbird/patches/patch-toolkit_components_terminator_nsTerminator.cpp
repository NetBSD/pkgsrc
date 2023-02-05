$NetBSD: patch-toolkit_components_terminator_nsTerminator.cpp,v 1.4 2023/02/05 09:05:29 he Exp $

--- toolkit/components/terminator/nsTerminator.cpp.orig	2020-08-28 21:33:46.000000000 +0000
+++ toolkit/components/terminator/nsTerminator.cpp
@@ -34,7 +34,7 @@
 #if defined(XP_WIN)
 #  include <windows.h>
 #else
-#  include <unistd.h>
+#  include <time.h>
 #endif
 
 #include "mozilla/AppShutdown.h"
@@ -184,7 +184,11 @@ void RunWatchdog(void* arg) {
 #if defined(XP_WIN)
     Sleep(HEARTBEAT_INTERVAL_MS /* ms */);
 #else
-    usleep(HEARTBEAT_INTERVAL_MS * 1000 /* usec */);
+    // usleep(HEARTBEAT_INTERVAL_MS * 1000 /* usec */);
+    struct timespec tickd;
+    tickd.tv_sec = 1;
+    tickd.tv_nsec = 0;
+    nanosleep(&tickd, NULL);
 #endif
 
     if (gHeartbeat++ < timeToLive) {
