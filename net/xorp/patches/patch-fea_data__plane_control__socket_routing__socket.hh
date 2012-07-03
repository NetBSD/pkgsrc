$NetBSD: patch-fea_data__plane_control__socket_routing__socket.hh,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- fea/data_plane/control_socket/routing_socket.hh.orig	2009-01-05 18:30:51.000000000 +0000
+++ fea/data_plane/control_socket/routing_socket.hh
@@ -142,7 +142,7 @@ private:
     static uint16_t _instance_cnt;
     static pid_t    _pid;
 
-    friend class RoutingSocketPlumber; // class that hooks observers in and out
+    friend struct RoutingSocketPlumber; // class that hooks observers in and out
 };
 
 class RoutingSocketObserver {
