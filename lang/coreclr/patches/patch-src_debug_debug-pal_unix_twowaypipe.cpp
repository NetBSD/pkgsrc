$NetBSD: patch-src_debug_debug-pal_unix_twowaypipe.cpp,v 1.1 2016/06/30 12:16:24 kamil Exp $

Revert:

commit 5ac6af932fe2a3f4b285b6dcc79010caf807ea9d
Author: Mike McLaughlin <mikem@microsoft.com>
Date:   Fri May 27 20:03:32 2016 -0700

    Fix the named semaphore leak on OSX (and Linux) (#5269)

It broke NetBSD.

--- src/debug/debug-pal/unix/twowaypipe.cpp.orig	2016-06-14 01:12:15.000000000 +0000
+++ src/debug/debug-pal/unix/twowaypipe.cpp
@@ -3,14 +3,31 @@
 // See the LICENSE file in the project root for more information.
 
 #include <pal.h>
+
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <limits.h>
 #include <pal_assert.h>
+
 #include "twowaypipe.h"
 
+static const char* PipeNameFormat = "/tmp/clr-debug-pipe-%d-%llu-%s";
+
+void TwoWayPipe::GetPipeName(char *name, DWORD id, const char *suffix)
+{
+    BOOL ret = GetProcessIdDisambiguationKey(id, &m_disambiguationKey);
+
+    // If GetProcessIdDisambiguationKey failed for some reason, it should set the value 
+    // to 0. We expect that anyone else making the pipe name will also fail and thus will
+    // also try to use 0 as the value.
+    _ASSERTE(ret == TRUE || m_disambiguationKey == 0);
+
+    int chars = _snprintf(name, MaxPipeNameLength, PipeNameFormat, id, m_disambiguationKey, suffix);
+    _ASSERTE(chars > 0 && chars < MaxPipeNameLength);
+}
+
 // Creates a server side of the pipe. 
 // Id is used to create pipes names and uniquely identify the pipe on the machine. 
 // true - success, false - failure (use GetLastError() for more details)
@@ -21,8 +38,8 @@ bool TwoWayPipe::CreateServer(DWORD id)
         return false;
 
     m_id = id;
-    PAL_GetTransportPipeName(m_inPipeName, id, "in");
-    PAL_GetTransportPipeName(m_outPipeName, id, "out");
+    GetPipeName(m_inPipeName, id, "in");
+    GetPipeName(m_outPipeName, id, "out");
 
     if (mkfifo(m_inPipeName, S_IRWXU) == -1)
     {
@@ -50,8 +67,8 @@ bool TwoWayPipe::Connect(DWORD id)
 
     m_id = id;
     //"in" and "out" are switched deliberately, because we're on the client
-    PAL_GetTransportPipeName(m_inPipeName, id, "out");
-    PAL_GetTransportPipeName(m_outPipeName, id, "in");
+    GetPipeName(m_inPipeName, id, "out");
+    GetPipeName(m_outPipeName, id, "in");
 
     // Pipe opening order is reversed compared to WaitForConnection()
     // in order to avaid deadlock.
@@ -190,4 +207,5 @@ void TwoWayPipe::CleanupTargetProcess()
 {
     unlink(m_inPipeName);
     unlink(m_outPipeName);
+    PAL_CleanupTargetProcess(m_id, m_disambiguationKey);
 }
