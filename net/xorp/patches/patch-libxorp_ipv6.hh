$NetBSD: patch-libxorp_ipv6.hh,v 1.2 2013/06/13 21:48:09 joerg Exp $

--- libxorp/ipv6.hh.orig	2009-01-05 18:30:58.000000000 +0000
+++ libxorp/ipv6.hh
@@ -281,6 +281,18 @@ public:
      */
     bool operator!=(const IPv6& other) const;
 
+    bool operator<=(const IPv6& other) const {
+	return other < *this || other == *this;
+    }
+
+    bool operator>=(const IPv6& other) const {
+	return other <= *this;
+    }
+
+    bool operator>(const IPv6& other) const {
+	return other < *this;
+    }
+
     /**
      * Equality Operator for @ref IPv6 against @ref IPv6Range operand.
      *
@@ -459,7 +471,7 @@ public:
      * @return address size in number of octets.
      */
     static size_t addr_bytelen() {
-	static_assert(sizeof(IPv6) == 4 * sizeof(uint32_t));
+	my_static_assert(sizeof(IPv6) == 4 * sizeof(uint32_t));
 	return sizeof(IPv6);
     }
 
