$NetBSD: patch-src_generic__mtrie__impl.hpp,v 1.1 2020/03/18 17:59:51 joerg Exp $

--- src/generic_mtrie_impl.hpp.orig	2020-03-14 19:34:04.836731020 +0000
+++ src/generic_mtrie_impl.hpp
@@ -49,7 +49,8 @@ zmq::generic_mtrie_t<T>::generic_mtrie_t
 {
 }
 
-template <typename T> zmq::generic_mtrie_t<T>::~generic_mtrie_t ()
+namespace zmq {
+template <typename T> generic_mtrie_t<T>::~generic_mtrie_t ()
 {
     LIBZMQ_DELETE (_pipes);
 
@@ -63,6 +64,7 @@ template <typename T> zmq::generic_mtrie
         free (_next.table);
     }
 }
+}
 
 template <typename T>
 bool zmq::generic_mtrie_t<T>::add (prefix_t prefix_,
