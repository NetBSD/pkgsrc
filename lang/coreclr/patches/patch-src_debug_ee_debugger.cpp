$NetBSD: patch-src_debug_ee_debugger.cpp,v 1.1 2016/06/30 12:16:24 kamil Exp $

Revert:                                                         

commit 5ac6af932fe2a3f4b285b6dcc79010caf807ea9d
Author: Mike McLaughlin <mikem@microsoft.com>
Date:   Fri May 27 20:03:32 2016 -0700

    Fix the named semaphore leak on OSX (and Linux) (#5269)

It broke NetBSD.

--- src/debug/ee/debugger.cpp.orig	2016-06-14 01:12:15.000000000 +0000
+++ src/debug/ee/debugger.cpp
@@ -2113,9 +2113,18 @@ HRESULT Debugger::Startup(void)
             ShutdownTransport();
             ThrowHR(hr);
         }
+
     #ifdef FEATURE_PAL
         PAL_SetShutdownCallback(AbortTransport);
     #endif // FEATURE_PAL
+
+         bool waitForAttach = CLRConfig::GetConfigValue(CLRConfig::UNSUPPORTED_DbgWaitForDebuggerAttach) != 0;
+         if (waitForAttach)
+         {
+             // Mark this process as launched by the debugger and the debugger as attached.
+             g_CORDebuggerControlFlags |= DBCF_GENERATE_DEBUG_CODE;
+             MarkDebuggerAttachedInternal();
+         }
     #endif // FEATURE_DBGIPC_TRANSPORT_VM
 
         RaiseStartupNotification();
