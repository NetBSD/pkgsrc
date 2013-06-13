$NetBSD: patch-libxorp_range.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- libxorp/range.hh.orig	2013-06-13 18:00:21.000000000 +0000
+++ libxorp/range.hh
@@ -59,6 +59,13 @@ public:
     const T& low() const { return _low; }
     const T& high() const { return _high; }
 
+    bool operator==(const Range& rhs) const {
+	return _low == rhs._low && _high == rhs._high;
+    }
+    bool operator!=(const Range& rhs) const {
+	return _low != rhs._low || _high != rhs._high;
+    }
+
 protected:
     T _low;
     T _high;
