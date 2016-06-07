$NetBSD: patch-libcult-1.4.2_cult_containers_map.hxx,v 1.1 2016/06/07 17:59:51 joerg Exp $

--- libcult-1.4.2/cult/containers/map.hxx.orig	2016-06-04 21:39:08.347062154 +0000
+++ libcult-1.4.2/cult/containers/map.hxx
@@ -54,6 +54,11 @@ namespace Cult
       IteratorAdapter<typename Base::const_iterator>
       ConstIterator;
 
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+      typedef ConstIterator EraseIterator;
+#else
+      typedef Iterator EraseIterator;
+#endif
 
       typedef
       IteratorAdapter<typename Base::reverse_iterator>
