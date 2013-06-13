$NetBSD: patch-libxorp_ipv4.hh,v 1.2 2013/06/13 21:48:09 joerg Exp $

--- libxorp/ipv4.hh.orig	2009-01-05 18:30:58.000000000 +0000
+++ libxorp/ipv4.hh
@@ -273,6 +273,15 @@ public:
      * right-hand operand.
      */
     bool operator<(const IPv4& other) const;
+    bool operator>(const IPv4& other) const {
+	return other < *this;
+    }
+    bool operator>=(const IPv4& other) const {
+	return *this > other || *this == other;
+    }
+    bool operator<=(const IPv4& other) const {
+	return *this < other || *this == other;
+    }
 
     /**
      * Equality Operator
@@ -506,7 +515,7 @@ public:
      * @return address size in number of octets.
      */
     static size_t addr_bytelen() {
-	static_assert(sizeof(IPv4) == sizeof(uint32_t));
+	my_static_assert(sizeof(IPv4) == sizeof(uint32_t));
 	return sizeof(IPv4);
     }
 
