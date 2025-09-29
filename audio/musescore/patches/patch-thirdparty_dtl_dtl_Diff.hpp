$NetBSD: patch-thirdparty_dtl_dtl_Diff.hpp,v 1.1 2025/09/29 20:50:44 mrg Exp $

GCC 14 does not like this const:
   Diff.hpp:166:27: error: assignment of member 'trivial' in read-only object


--- thirdparty/dtl/dtl/Diff.hpp.orig	2021-02-08 04:16:37.000000000 -0800
+++ thirdparty/dtl/dtl/Diff.hpp	2025-09-26 12:20:01.426062508 -0700
@@ -162,7 +162,7 @@
             return trivial;
         }
         
-        void enableTrivial () const {
+        void enableTrivial () {
             this->trivial = true;
         }
         
