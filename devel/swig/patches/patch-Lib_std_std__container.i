$NetBSD: patch-Lib_std_std__container.i,v 1.1 2013/05/11 21:30:09 joerg Exp $

--- Lib/std/std_container.i.orig	2008-03-26 20:25:56.000000000 +0000
+++ Lib/std/std_container.i
@@ -46,8 +46,8 @@
   void resize(size_type new_size);
   
   #ifdef SWIG_EXPORT_ITERATOR_METHODS
-  iterator erase(iterator pos);
-  iterator erase(iterator first, iterator last);
+  iterator erase(const_iterator pos);
+  iterator erase(const_iterator first, const_iterator last);
   #endif
   
 %enddef
@@ -68,8 +68,8 @@
   void resize(size_type new_size, const value_type& x);
   
   #ifdef SWIG_EXPORT_ITERATOR_METHODS
-  iterator insert(iterator pos, const value_type& x);
-  void insert(iterator pos, size_type n, const value_type& x);
+  iterator insert(const_iterator pos, const value_type& x);
+  void insert(const_iterator pos, size_type n, const value_type& x);
   #endif
   
 %enddef
@@ -89,8 +89,8 @@
   void resize(size_type new_size, value_type x);
   
   #ifdef SWIG_EXPORT_ITERATOR_METHODS
-  iterator insert(iterator pos, value_type x);
-  void insert(iterator pos, size_type n, value_type x);
+  iterator insert(const_iterator pos, value_type x);
+  void insert(const_iterator pos, size_type n, value_type x);
   #endif
   
 %enddef
