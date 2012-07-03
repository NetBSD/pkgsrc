$NetBSD: patch-fea_data__plane_control__socket_netlink__socket.hh,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- fea/data_plane/control_socket/netlink_socket.hh.orig	2009-01-05 18:30:51.000000000 +0000
+++ fea/data_plane/control_socket/netlink_socket.hh
@@ -208,7 +208,7 @@ private:
     uint32_t	_nl_groups;	// The netlink multicast groups to listen for
     bool	_is_multipart_message_read; // If true, expect to read a multipart message
 
-    friend class NetlinkSocketPlumber; // class that hooks observers in and out
+    friend struct NetlinkSocketPlumber; // class that hooks observers in and out
 };
 
 class NetlinkSocketObserver {
