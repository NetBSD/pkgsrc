$NetBSD: patch-libxorp_asnum.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- libxorp/asnum.hh.orig	2013-06-13 18:35:47.000000000 +0000
+++ libxorp/asnum.hh
@@ -209,6 +209,7 @@ public:
      * right-hand operand.
      */
     bool operator==(const AsNum& x) const		{ return _as == x._as; }
+    bool operator!=(const AsNum& x) const		{ return _as != x._as; }
 
     /**
      * Less-Than Operator
