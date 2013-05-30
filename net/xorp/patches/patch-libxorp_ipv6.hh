$NetBSD: patch-libxorp_ipv6.hh,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- libxorp/ipv6.hh.orig	2013-04-29 19:22:56.000000000 +0000
+++ libxorp/ipv6.hh
@@ -459,7 +459,7 @@ public:
      * @return address size in number of octets.
      */
     static size_t addr_bytelen() {
-	static_assert(sizeof(IPv6) == 4 * sizeof(uint32_t));
+	my_static_assert(sizeof(IPv6) == 4 * sizeof(uint32_t));
 	return sizeof(IPv6);
     }
 
