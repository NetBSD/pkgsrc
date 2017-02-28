$NetBSD: patch-src_OR__Matrix__inlines.hh,v 1.1 2017/02/28 15:01:27 joerg Exp $

--- src/OR_Matrix_inlines.hh.orig	2017-02-27 13:14:25.020701853 +0000
+++ src/OR_Matrix_inlines.hh
@@ -97,7 +97,7 @@ OR_Matrix<T>::Pseudo_Row<U>::Pseudo_Row(
 
 template <typename T>
 template <typename U>
-inline OR_Matrix<T>::Pseudo_Row<U>&
+inline typename OR_Matrix<T>::template Pseudo_Row<U>&
 OR_Matrix<T>::Pseudo_Row<U>::operator=(const Pseudo_Row& y) {
   first = y.first;
 #if PPL_OR_MATRIX_EXTRA_DEBUG
