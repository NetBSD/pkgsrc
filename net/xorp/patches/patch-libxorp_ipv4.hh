$NetBSD: patch-libxorp_ipv4.hh,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- libxorp/ipv4.hh.orig	2013-04-29 19:22:58.000000000 +0000
+++ libxorp/ipv4.hh
@@ -506,7 +506,7 @@ public:
      * @return address size in number of octets.
      */
     static size_t addr_bytelen() {
-	static_assert(sizeof(IPv4) == sizeof(uint32_t));
+	my_static_assert(sizeof(IPv4) == sizeof(uint32_t));
 	return sizeof(IPv4);
     }
 
