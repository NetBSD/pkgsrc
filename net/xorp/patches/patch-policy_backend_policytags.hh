$NetBSD: patch-policy_backend_policytags.hh,v 1.1 2013/06/13 21:48:09 joerg Exp $

--- policy/backend/policytags.hh.orig	2013-06-13 19:41:47.000000000 +0000
+++ policy/backend/policytags.hh
@@ -73,6 +73,9 @@ public:
      * @param rhs PolicyTags to compare with.
      */
     bool operator==(const PolicyTags& rhs) const;
+    bool operator!=(const PolicyTags& rhs) const {
+	return !(*this == rhs);
+    }
 
     /**
      * Convert to an ElemSet.
