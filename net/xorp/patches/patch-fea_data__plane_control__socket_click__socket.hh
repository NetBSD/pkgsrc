$NetBSD: patch-fea_data__plane_control__socket_click__socket.hh,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- fea/data_plane/control_socket/click_socket.hh.orig	2009-01-05 18:30:51.000000000 +0000
+++ fea/data_plane/control_socket/click_socket.hh
@@ -550,7 +550,7 @@ private:
 
     RunCommand*	_user_click_run_command;
     
-    friend class ClickSocketPlumber; // class that hooks observers in and out
+    friend struct ClickSocketPlumber; // class that hooks observers in and out
 };
 
 class ClickSocketObserver {
