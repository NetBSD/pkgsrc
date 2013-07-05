$NetBSD: patch-avahi-core_socket.c,v 1.1 2013/07/05 16:28:43 ryoon Exp $

* Fix build on NetBSD 6.99.23.
  From martin@'s post on tech-pkg@.

--- avahi-core/socket.c.orig	2011-04-25 00:12:18.000000000 +0000
+++ avahi-core/socket.c
@@ -528,7 +528,11 @@ int avahi_send_dns_packet_ipv4(
             pkti->ipi_ifindex = interface;
 
         if (src_address)
+#ifdef __linux__
             pkti->ipi_spec_dst.s_addr = src_address->address;
+#else
+            pkti->ipi_addr.s_addr = src_address->address;
+#endif
     }
 #elif defined(IP_MULTICAST_IF)
     if (src_address) {
