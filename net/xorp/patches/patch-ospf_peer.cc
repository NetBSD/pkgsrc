$NetBSD: patch-ospf_peer.cc,v 1.2 2013/05/30 15:37:24 joerg Exp $

--- ospf/peer.cc.orig	2009-01-05 18:31:01.000000000 +0000
+++ ospf/peer.cc
@@ -170,12 +170,12 @@ PeerOut<A>::get_frame_size() const
     switch(_ospf.get_version()) {
     case OspfTypes::V2:
 	frame -= sizeof(struct ip);
-	static_assert(20 == sizeof(struct ip));
+	my_static_assert(20 == sizeof(struct ip));
 	break;
     case OspfTypes::V3:
 #ifdef HAVE_NETINET_IP6_H
 	frame -= sizeof(struct ip6_hdr);
-	static_assert(40 == sizeof(struct ip6_hdr));
+	my_static_assert(40 == sizeof(struct ip6_hdr));
 #else
 	frame -= 40;
 #endif
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
 
