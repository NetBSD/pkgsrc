$NetBSD: patch-pstream.h,v 1.1 2012/11/23 12:26:56 joerg Exp $

The fd_type type is not defined in basic_streambuf, so be consistent
with the definition of wpipe() and friends.

--- pstream.h.orig	2010-03-20 14:50:47.000000000 +0000
+++ pstream.h
@@ -1816,7 +1816,7 @@ namespace redi
 
   /** @return a reference to the output file descriptor */
   template <typename C, typename T>
-    inline typename basic_pstreambuf<C,T>::fd_type&
+    inline typename pstreambuf::fd_type&
     basic_pstreambuf<C,T>::wpipe()
     {
       return wpipe_;
@@ -1824,7 +1824,7 @@ namespace redi
 
   /** @return a reference to the active input file descriptor */
   template <typename C, typename T>
-    inline typename basic_pstreambuf<C,T>::fd_type&
+    inline typename pstream::fd_type&
     basic_pstreambuf<C,T>::rpipe()
     {
       return rpipe_[rsrc_];
@@ -1832,7 +1832,7 @@ namespace redi
 
   /** @return a reference to the specified input file descriptor */
   template <typename C, typename T>
-    inline typename basic_pstreambuf<C,T>::fd_type&
+    inline typename pstream::fd_type&
     basic_pstreambuf<C,T>::rpipe(buf_read_src which)
     {
       return rpipe_[which];
