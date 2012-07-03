$NetBSD: patch-ospf_peer.cc,v 1.1 2012/07/03 17:36:10 joerg Exp $

--- ospf/peer.cc.orig	2009-01-05 18:31:01.000000000 +0000
+++ ospf/peer.cc
@@ -301,19 +301,16 @@ template <typename A>
 void
 PeerOut<A>::peer_change()
 {
-    switch (_running) {
-    case true:
+    if (_running) {
 	if (false == _status || false == _link_status) {
 	    take_down_peering();
 	    _running = false;
 	}
-	break;
-    case false:
+    } else {
 	if (true == _status && true == _link_status) {
 	    _running = true;
 	    _running = bring_up_peering();
 	}
-	break;
     }
 }
 
