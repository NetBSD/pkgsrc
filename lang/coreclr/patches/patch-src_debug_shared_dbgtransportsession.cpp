$NetBSD: patch-src_debug_shared_dbgtransportsession.cpp,v 1.1 2016/06/30 12:16:24 kamil Exp $

Revert:                                                         

commit 5ac6af932fe2a3f4b285b6dcc79010caf807ea9d
Author: Mike McLaughlin <mikem@microsoft.com>
Date:   Fri May 27 20:03:32 2016 -0700

    Fix the named semaphore leak on OSX (and Linux) (#5269)

It broke NetBSD.

--- src/debug/shared/dbgtransportsession.cpp.orig	2016-06-14 01:12:15.000000000 +0000
+++ src/debug/shared/dbgtransportsession.cpp
@@ -130,11 +130,6 @@ HRESULT DbgTransportSession::Init(Debugg
     m_hSessionOpenEvent = WszCreateEvent(NULL, TRUE, FALSE, NULL); // Manual reset, not signalled
     if (m_hSessionOpenEvent == NULL)
         return E_OUTOFMEMORY;
-#else // RIGHT_SIDE_COMPILE
-    DWORD pid = GetCurrentProcessId(); 
-    if (!m_pipe.CreateServer(pid)) {
-        return E_OUTOFMEMORY;
-    }
 #endif // RIGHT_SIDE_COMPILE
 
     // Allocate some buffers to receive incoming events. The initial number is chosen arbitrarily, tune as
@@ -1350,8 +1345,7 @@ void DbgTransportSession::TransportWorke
         else
         {
             DWORD pid = GetCurrentProcessId(); 
-            if ((m_pipe.GetState() == TwoWayPipe::Created || m_pipe.CreateServer(pid)) && 
-                 m_pipe.WaitForConnection())
+            if (m_pipe.CreateServer(pid) && m_pipe.WaitForConnection())
             {
                 eStatus = SCS_Success;
             }
