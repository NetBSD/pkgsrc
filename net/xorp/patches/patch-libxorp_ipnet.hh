$NetBSD: patch-libxorp_ipnet.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- libxorp/ipnet.hh.orig	2013-06-13 18:24:26.000000000 +0000
+++ libxorp/ipnet.hh
@@ -107,6 +107,10 @@ public:
 		(masked_addr() == other.masked_addr()));
     }
 
+    bool operator!=(const IPNet& other) const {
+	return !(*this == other);
+    }
+
     /**
      * Less-than comparison for subnets (see body for description).
      *
