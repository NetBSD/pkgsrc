$NetBSD: patch-Eigen_src_Sparse_AmbiVector.h,v 1.1 2019/09/09 12:05:01 maya Exp $

We're returning an int, so match prototype.

--- Eigen/src/Sparse/AmbiVector.h.orig	2019-09-09 11:56:26.894097747 +0000
+++ Eigen/src/Sparse/AmbiVector.h
@@ -44,7 +44,7 @@ template<typename _Scalar> class AmbiVec
     void init(RealScalar estimatedDensity);
     void init(int mode);
 
-    void nonZeros() const;
+    int nonZeros() const;
 
     /** Specifies a sub-vector to work on */
     void setBounds(int start, int end) { m_start = start; m_end = end; }
@@ -133,7 +133,7 @@ template<typename _Scalar> class AmbiVec
 
 /** \returns the number of non zeros in the current sub vector */
 template<typename Scalar>
-void AmbiVector<Scalar>::nonZeros() const
+int AmbiVector<Scalar>::nonZeros() const
 {
   if (m_mode==IsSparse)
     return m_llSize;
