$NetBSD: patch-src_PYUtil.h,v 1.1 2012/04/22 14:02:50 obache Exp $

* error `already defined' on NetBSD-5.1.2. 

--- src/PYUtil.h.orig	2011-09-17 02:43:37.000000000 +0000
+++ src/PYUtil.h
@@ -43,7 +43,7 @@
 
 namespace std {
     // import boost::shared_ptr to std namespace
-    using boost::shared_ptr;
+    // using boost::shared_ptr;
     // import boost::scoped_ptr to std namespace, and rename to unique_ptr
     // XXX: the unique_ptr can transfer the pointer ownership,
     //      but scoped_ptr cannot.
