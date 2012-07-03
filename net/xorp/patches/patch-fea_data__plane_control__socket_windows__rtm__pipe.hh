$NetBSD: patch-fea_data__plane_control__socket_windows__rtm__pipe.hh,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- fea/data_plane/control_socket/windows_rtm_pipe.hh.orig	2009-01-05 18:30:51.000000000 +0000
+++ fea/data_plane/control_socket/windows_rtm_pipe.hh
@@ -135,7 +135,7 @@ private:
     static uint16_t _instance_cnt;
     static pid_t    _pid;
 
-    friend class WinRtmPipePlumber; // class that hooks observers in and out
+    friend struct WinRtmPipePlumber; // class that hooks observers in and out
 };
 
 class WinRtmPipeObserver {
