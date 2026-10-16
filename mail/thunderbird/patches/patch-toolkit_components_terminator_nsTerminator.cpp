$NetBSD: patch-toolkit_components_terminator_nsTerminator.cpp,v 1.7 2026/10/16 16:36:08 ryoon Exp $

* Fix segfault on exit under NetBSD

--- toolkit/components/terminator/nsTerminator.cpp.orig	2026-10-08 02:24:22.000000000 +0000
+++ toolkit/components/terminator/nsTerminator.cpp
@@ -33,7 +33,7 @@
 #if defined(XP_WIN)
 #  include <windows.h>
 #else
-#  include <unistd.h>
+#  include <time.h>
 #endif
 
 #include "mozilla/AppShutdown.h"
@@ -223,7 +223,10 @@ void RunWatchdog(void*) {
 #if defined(XP_WIN)
     Sleep(HEARTBEAT_INTERVAL_MS /* ms */);
 #else
-    usleep(HEARTBEAT_INTERVAL_MS * 1000 /* usec */);
+    struct timespec tickd;
+    tickd.tv_sec = 0;
+    tickd.tv_nsec = HEARTBEAT_INTERVAL_MS * 1000 * 1000;
+    nanosleep(&tickd, NULL);
 #endif
 
     if (gHeartbeat++ < gCrashAfterTicks) {
