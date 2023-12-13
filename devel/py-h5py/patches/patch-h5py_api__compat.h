$NetBSD: patch-h5py_api__compat.h,v 1.1 2023/12/13 20:29:09 wiz Exp $

Fix build with Cython 3.
https://github.com/h5py/h5py/pull/2345

--- h5py/api_compat.h.orig	2021-05-09 11:55:36.000000000 +0000
+++ h5py/api_compat.h
@@ -24,7 +24,6 @@ typedef void *PyMPI_MPI_Message;
 #include <stddef.h>
 #include "Python.h"
 #include "numpy/arrayobject.h"
-#include "hdf5.h"
 
 /* The HOFFSET macro can't be used from Cython. */
 
@@ -35,14 +34,14 @@ typedef void *PyMPI_MPI_Message;
 #define h5py_size_n256 (sizeof(npy_complex256))
 #endif
 
-#define h5py_offset_n64_real (HOFFSET(npy_complex64, real))
-#define h5py_offset_n64_imag (HOFFSET(npy_complex64, imag))
-#define h5py_offset_n128_real (HOFFSET(npy_complex128, real))
-#define h5py_offset_n128_imag (HOFFSET(npy_complex128, imag))
+#define h5py_offset_n64_real (0)
+#define h5py_offset_n64_imag (sizeof(float))
+#define h5py_offset_n128_real (0)
+#define h5py_offset_n128_imag (sizeof(double))
 
 #ifdef NPY_COMPLEX256
-#define h5py_offset_n256_real (HOFFSET(npy_complex256, real))
-#define h5py_offset_n256_imag (HOFFSET(npy_complex256, imag))
+#define h5py_offset_n256_real (0)
+#define h5py_offset_n256_imag (sizeof(long double))
 #endif
 
 #endif
