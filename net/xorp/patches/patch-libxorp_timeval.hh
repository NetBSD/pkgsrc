$NetBSD: patch-libxorp_timeval.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- libxorp/timeval.hh.orig	2013-06-13 18:08:49.000000000 +0000
+++ libxorp/timeval.hh
@@ -239,6 +239,9 @@ public:
      * right-hand operand.
      */
     bool operator==(const TimeVal& other) const;
+    bool operator!=(const TimeVal& other) const {
+	return !(*this == other);
+    }
 
     /**
      * Less-Than Operator
@@ -249,6 +252,18 @@ public:
      */
     bool operator<(const TimeVal& other) const;
 
+    bool operator>(const TimeVal& other) const {
+	return other < *this;
+    }
+
+    bool operator>=(const TimeVal& other) const {
+	return other <= *this;
+    }
+
+    bool operator<=(const TimeVal& other) const {
+	return *this <= other || *this == other;
+    }
+
     /**
      * Assign-Sum Operator
      *
