$NetBSD: patch-src_pal_inc_pal.h,v 1.1 2016/06/30 12:16:24 kamil Exp $

Revert:                                                         

commit 5ac6af932fe2a3f4b285b6dcc79010caf807ea9d
Author: Mike McLaughlin <mikem@microsoft.com>
Date:   Fri May 27 20:03:32 2016 -0700

    Fix the named semaphore leak on OSX (and Linux) (#5269)

It broke NetBSD.

--- src/pal/inc/pal.h.orig	2016-06-14 01:12:15.000000000 +0000
+++ src/pal/inc/pal.h
@@ -583,12 +583,12 @@ BOOL
 PALAPI
 PAL_NotifyRuntimeStarted();
 
-static const int MAX_DEBUGGER_TRANSPORT_PIPE_NAME_LENGTH = 64;
-
 PALIMPORT
-void
+VOID
 PALAPI
-PAL_GetTransportPipeName(char *name, DWORD id, const char *suffix);
+PAL_CleanupTargetProcess(
+    IN int pid, 
+    IN UINT64 disambiguationKey);
 
 PALIMPORT
 void
@@ -1690,6 +1690,13 @@ GetProcessTimes(
         OUT LPFILETIME lpKernelTime,
         OUT LPFILETIME lpUserTime);
 
+PALIMPORT
+BOOL
+PALAPI
+GetProcessIdDisambiguationKey(
+        IN DWORD processId,
+        OUT UINT64 *disambiguationKey);
+
 #define MAXIMUM_WAIT_OBJECTS  64
 #define WAIT_OBJECT_0 0
 #define WAIT_ABANDONED   0x00000080
