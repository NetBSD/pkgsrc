$NetBSD: patch-modules_core_src_hal__internal.cpp,v 1.1 2021/09/22 13:40:41 nia Exp $

https://bugs.gentoo.org/800539
https://github.com/opencv/opencv/issues/19846

--- modules/core/src/hal_internal.cpp.orig	2019-12-19 15:16:47.000000000 +0000
+++ modules/core/src/hal_internal.cpp
@@ -162,9 +162,9 @@ lapack_Cholesky(fptype* a, size_t a_step
         if(n == 1 && b_step == sizeof(fptype))
         {
             if(typeid(fptype) == typeid(float))
-                sposv_(L, &m, &n, (float*)a, &lda, (float*)b, &m, &lapackStatus);
+                LAPACK_sposv_(L, &m, &n, (float*)a, &lda, (float*)b, &m, &lapackStatus);
             else if(typeid(fptype) == typeid(double))
-                dposv_(L, &m, &n, (double*)a, &lda, (double*)b, &m, &lapackStatus);
+                LAPACK_dposv_(L, &m, &n, (double*)a, &lda, (double*)b, &m, &lapackStatus);
         }
         else
         {
@@ -173,9 +173,9 @@ lapack_Cholesky(fptype* a, size_t a_step
             transpose(b, ldb, tmpB, m, m, n);
 
             if(typeid(fptype) == typeid(float))
-                sposv_(L, &m, &n, (float*)a, &lda, (float*)tmpB, &m, &lapackStatus);
+                LAPACK_sposv_(L, &m, &n, (float*)a, &lda, (float*)tmpB, &m, &lapackStatus);
             else if(typeid(fptype) == typeid(double))
-                dposv_(L, &m, &n, (double*)a, &lda, (double*)tmpB, &m, &lapackStatus);
+                LAPACK_dposv_(L, &m, &n, (double*)a, &lda, (double*)tmpB, &m, &lapackStatus);
 
             transpose(tmpB, m, b, ldb, n, m);
             delete[] tmpB;
@@ -184,9 +184,9 @@ lapack_Cholesky(fptype* a, size_t a_step
     else
     {
         if(typeid(fptype) == typeid(float))
-            spotrf_(L, &m, (float*)a, &lda, &lapackStatus);
+            LAPACK_spotrf_(L, &m, (float*)a, &lda, &lapackStatus);
         else if(typeid(fptype) == typeid(double))
-            dpotrf_(L, &m, (double*)a, &lda, &lapackStatus);
+            LAPACK_dpotrf_(L, &m, (double*)a, &lda, &lapackStatus);
     }
 
     if(lapackStatus == 0) *info = true;
@@ -226,17 +226,17 @@ lapack_SVD(fptype* a, size_t a_step, fpt
     }
 
     if(typeid(fptype) == typeid(float))
-        sgesdd_(mode, &m, &n, (float*)a, &lda, (float*)w, (float*)u, &ldu, (float*)vt, &ldv, (float*)&work1, &lwork, iworkBuf, info);
+        LAPACK_sgesdd_(mode, &m, &n, (float*)a, &lda, (float*)w, (float*)u, &ldu, (float*)vt, &ldv, (float*)&work1, &lwork, iworkBuf, info);
     else if(typeid(fptype) == typeid(double))
-        dgesdd_(mode, &m, &n, (double*)a, &lda, (double*)w, (double*)u, &ldu, (double*)vt, &ldv, (double*)&work1, &lwork, iworkBuf, info);
+        LAPACK_dgesdd_(mode, &m, &n, (double*)a, &lda, (double*)w, (double*)u, &ldu, (double*)vt, &ldv, (double*)&work1, &lwork, iworkBuf, info);
 
     lwork = (int)round(work1); //optimal buffer size
     fptype* buffer = new fptype[lwork + 1];
 
     if(typeid(fptype) == typeid(float))
-        sgesdd_(mode, &m, &n, (float*)a, &lda, (float*)w, (float*)u, &ldu, (float*)vt, &ldv, (float*)buffer, &lwork, iworkBuf, info);
+        LAPACK_sgesdd_(mode, &m, &n, (float*)a, &lda, (float*)w, (float*)u, &ldu, (float*)vt, &ldv, (float*)buffer, &lwork, iworkBuf, info);
     else if(typeid(fptype) == typeid(double))
-        dgesdd_(mode, &m, &n, (double*)a, &lda, (double*)w, (double*)u, &ldu, (double*)vt, &ldv, (double*)buffer, &lwork, iworkBuf, info);
+        LAPACK_dgesdd_(mode, &m, &n, (double*)a, &lda, (double*)w, (double*)u, &ldu, (double*)vt, &ldv, (double*)buffer, &lwork, iworkBuf, info);
 
     if(!(flags & CV_HAL_SVD_NO_UV))
         transpose_square_inplace(vt, ldv, n);
@@ -287,18 +287,18 @@ lapack_QR(fptype* a, size_t a_step, int 
         if (k == 1 && b_step == sizeof(fptype))
         {
             if (typeid(fptype) == typeid(float))
-                sgels_(mode, &m, &n, &k, (float*)tmpA, &ldtmpA, (float*)b, &m, (float*)&work1, &lwork, info);
+                LAPACK_sgels_(mode, &m, &n, &k, (float*)tmpA, &ldtmpA, (float*)b, &m, (float*)&work1, &lwork, info);
             else if (typeid(fptype) == typeid(double))
-                dgels_(mode, &m, &n, &k, (double*)tmpA, &ldtmpA, (double*)b, &m, (double*)&work1, &lwork, info);
+                LAPACK_dgels_(mode, &m, &n, &k, (double*)tmpA, &ldtmpA, (double*)b, &m, (double*)&work1, &lwork, info);
 
             lwork = cvRound(work1); //optimal buffer size
             std::vector<fptype> workBufMemHolder(lwork + 1);
             fptype* buffer = &workBufMemHolder.front();
 
             if (typeid(fptype) == typeid(float))
-                sgels_(mode, &m, &n, &k, (float*)tmpA, &ldtmpA, (float*)b, &m, (float*)buffer, &lwork, info);
+                LAPACK_sgels_(mode, &m, &n, &k, (float*)tmpA, &ldtmpA, (float*)b, &m, (float*)buffer, &lwork, info);
             else if (typeid(fptype) == typeid(double))
-                dgels_(mode, &m, &n, &k, (double*)tmpA, &ldtmpA, (double*)b, &m, (double*)buffer, &lwork, info);
+                LAPACK_dgels_(mode, &m, &n, &k, (double*)tmpA, &ldtmpA, (double*)b, &m, (double*)buffer, &lwork, info);
         }
         else
         {
@@ -308,18 +308,18 @@ lapack_QR(fptype* a, size_t a_step, int 
             transpose(b, ldb, tmpB, m, m, k);
 
             if (typeid(fptype) == typeid(float))
-                sgels_(mode, &m, &n, &k, (float*)tmpA, &ldtmpA, (float*)tmpB, &m, (float*)&work1, &lwork, info);
+                LAPACK_sgels_(mode, &m, &n, &k, (float*)tmpA, &ldtmpA, (float*)tmpB, &m, (float*)&work1, &lwork, info);
             else if (typeid(fptype) == typeid(double))
-                dgels_(mode, &m, &n, &k, (double*)tmpA, &ldtmpA, (double*)tmpB, &m, (double*)&work1, &lwork, info);
+                LAPACK_dgels_(mode, &m, &n, &k, (double*)tmpA, &ldtmpA, (double*)tmpB, &m, (double*)&work1, &lwork, info);
 
             lwork = cvRound(work1); //optimal buffer size
             std::vector<fptype> workBufMemHolder(lwork + 1);
             fptype* buffer = &workBufMemHolder.front();
 
             if (typeid(fptype) == typeid(float))
-                sgels_(mode, &m, &n, &k, (float*)tmpA, &ldtmpA, (float*)tmpB, &m, (float*)buffer, &lwork, info);
+                LAPACK_sgels_(mode, &m, &n, &k, (float*)tmpA, &ldtmpA, (float*)tmpB, &m, (float*)buffer, &lwork, info);
             else if (typeid(fptype) == typeid(double))
-                dgels_(mode, &m, &n, &k, (double*)tmpA, &ldtmpA, (double*)tmpB, &m, (double*)buffer, &lwork, info);
+                LAPACK_dgels_(mode, &m, &n, &k, (double*)tmpA, &ldtmpA, (double*)tmpB, &m, (double*)buffer, &lwork, info);
 
             transpose(tmpB, m, b, ldb, k, m);
         }
