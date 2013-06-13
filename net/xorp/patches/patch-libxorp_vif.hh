$NetBSD: patch-libxorp_vif.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- libxorp/vif.hh.orig	2013-06-13 18:49:34.000000000 +0000
+++ libxorp/vif.hh
@@ -168,6 +168,9 @@ public:
      * right-hand operand.
      */
     bool operator==(const VifAddr& other) const;
+    bool operator!=(const VifAddr& other) const {
+	return !(*this == other);
+    }
     
 private:
     IPvX	_addr;				// IP address of the vif
