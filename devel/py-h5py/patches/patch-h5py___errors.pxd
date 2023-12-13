$NetBSD: patch-h5py___errors.pxd,v 1.1 2023/12/13 20:29:09 wiz Exp $

Fix build with Cython 3.
https://github.com/h5py/h5py/pull/2345

--- h5py/_errors.pxd.orig	2023-10-04 09:21:14.000000000 +0000
+++ h5py/_errors.pxd
@@ -425,4 +425,4 @@ ctypedef struct err_cookie:
 cdef err_cookie set_error_handler(err_cookie handler)
 
 # Set the default error handler set by silence_errors/unsilence_errors
-cdef void set_default_error_handler() nogil
+cdef void set_default_error_handler() noexcept nogil
