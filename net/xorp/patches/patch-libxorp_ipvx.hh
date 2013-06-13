$NetBSD: patch-libxorp_ipvx.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- libxorp/ipvx.hh.orig	2013-06-13 19:31:17.000000000 +0000
+++ libxorp/ipvx.hh
@@ -344,6 +344,9 @@ public:
      * right-hand operand.
      */
     bool operator<(const IPvX& other) const;
+    bool operator>(const IPvX& other) const {
+	return other < *this;
+    }
 
     /**
      * Equality Operator
