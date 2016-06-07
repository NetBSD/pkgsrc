$NetBSD: patch-libbackend-elements-1.6.1_backend-elements_indentation_cxx.hxx,v 1.2 2016/06/07 17:59:51 joerg Exp $

--- libbackend-elements-1.6.1/backend-elements/indentation/cxx.hxx.orig	2013-05-14 20:12:33.000000000 +0000
+++ libbackend-elements-1.6.1/backend-elements/indentation/cxx.hxx
@@ -506,7 +506,7 @@ namespace BackendElements
 
             // Reduce double newline after "}" into a single one.
             //
-            typename Hold::Iterator i (hold_.end ()), b (hold_.begin ());
+            typename Hold::EraseIterator i (hold_.end ()), b (hold_.begin ());
 
             for (--i; i != b; --i)
             {
