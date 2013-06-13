$NetBSD: patch-libxipc_xrl__atom.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- libxipc/xrl_atom.hh.orig	2013-06-13 18:11:47.000000000 +0000
+++ libxipc/xrl_atom.hh
@@ -398,6 +398,9 @@ public:
 
     // Equality tests
     bool operator==(const XrlAtom& x) const;
+    bool operator!=(const XrlAtom& x) const {
+	return !(*this == x);
+    }
 
     // Binary packing and unpacking operations
     bool packed_bytes_fixed() const;
