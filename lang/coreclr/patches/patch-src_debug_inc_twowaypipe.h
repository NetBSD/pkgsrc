$NetBSD: patch-src_debug_inc_twowaypipe.h,v 1.1 2016/06/30 12:16:24 kamil Exp $

Revert:                                                         

commit 5ac6af932fe2a3f4b285b6dcc79010caf807ea9d
Author: Mike McLaughlin <mikem@microsoft.com>
Date:   Fri May 27 20:03:32 2016 -0700

    Fix the named semaphore leak on OSX (and Linux) (#5269)

It broke NetBSD.

--- src/debug/inc/twowaypipe.h.orig	2016-06-14 01:12:15.000000000 +0000
+++ src/debug/inc/twowaypipe.h
@@ -81,12 +81,18 @@ private:
 
     State m_state;
 
+
 #ifdef FEATURE_PAL
 
+    static const int MaxPipeNameLength = 64;
+
+    void GetPipeName(char *name, DWORD id, const char *suffix);
+
     int m_id;                               // id that was passed to CreateServer() or Connect()
     int m_inboundPipe, m_outboundPipe;      // two one sided pipes used for communication
-    char m_inPipeName[MAX_DEBUGGER_TRANSPORT_PIPE_NAME_LENGTH];   // filename of the inbound pipe
-    char m_outPipeName[MAX_DEBUGGER_TRANSPORT_PIPE_NAME_LENGTH];  // filename of the outbound pipe
+    UINT64 m_disambiguationKey;             // key to make the names more unique
+    char m_inPipeName[MaxPipeNameLength];   // filename of the inbound pipe
+    char m_outPipeName[MaxPipeNameLength];  // filename of the outbound pipe
 
 #else
     // Connects to a one sided pipe previously created by CreateOneWayPipe.
