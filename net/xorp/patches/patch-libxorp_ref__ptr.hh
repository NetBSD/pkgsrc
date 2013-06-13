$NetBSD: patch-libxorp_ref__ptr.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- libxorp/ref_ptr.hh.orig	2013-06-13 19:17:52.000000000 +0000
+++ libxorp/ref_ptr.hh
@@ -198,6 +198,7 @@ public:
      * @return true if reference pointers refer to same object.
      */
     bool operator==(const ref_ptr& rp) const { return _M_ptr == rp._M_ptr; }
+    bool operator!=(const ref_ptr& rp) const { return _M_ptr != rp._M_ptr; }
 
     /**
      * Check if reference pointer refers to an object or whether it has
