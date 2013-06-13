$NetBSD: patch-bgp_aspath.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- bgp/aspath.hh.orig	2013-06-13 18:38:08.000000000 +0000
+++ bgp/aspath.hh
@@ -262,6 +262,9 @@ public:
      * compares internal representations for equality.
      */
     bool operator==(const ASSegment& him) const;
+    bool operator!=(const ASSegment& him) const {
+	return !(*this == him);
+    }
 
     /**
      * Compares internal representations for <.
@@ -433,6 +436,9 @@ public:
     ASPath& operator=(const ASPath& him);
 
     bool operator==(const ASPath& him) const;
+    bool operator!=(const ASPath& him) const {
+	return !(*this == him);
+    }
 
     bool operator<(const ASPath& him) const;
 
