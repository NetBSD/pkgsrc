$NetBSD: patch-src_NetworkInterface.cpp,v 1.1 2019/07/12 09:33:22 adam Exp $

Fix for newer ndpi.

--- src/NetworkInterface.cpp.orig	2019-07-11 16:55:03.000000000 +0000
+++ src/NetworkInterface.cpp
@@ -1604,7 +1604,8 @@ bool NetworkInterface::processPacket(u_i
 	  ndpi_protocol icmp_proto = flow->get_detected_protocol();
 
 	  if(icmp_proto.category == NDPI_PROTOCOL_CATEGORY_UNSPECIFIED) {
-	    ndpi_fill_ip_protocol_category(ndpi_struct, (struct ndpi_iphdr *)ip, &icmp_proto);
+	    ndpi_fill_ip_protocol_category(ndpi_struct,
+              ((struct ndpi_iphdr*)ip)->saddr, ((struct ndpi_iphdr*)ip)->daddr, &icmp_proto);
 	    flow->setDetectedProtocol(icmp_proto, false);
 	  }
 	}
