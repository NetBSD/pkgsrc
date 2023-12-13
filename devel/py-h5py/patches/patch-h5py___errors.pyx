$NetBSD: patch-h5py___errors.pyx,v 1.1 2023/12/13 20:29:09 wiz Exp $

Fix build with Cython 3.
https://github.com/h5py/h5py/pull/2345

--- h5py/_errors.pyx.orig	2023-04-26 15:08:31.000000000 +0000
+++ h5py/_errors.pyx
@@ -94,7 +94,7 @@ cdef struct err_data_t:
     H5E_error_t err
     int n
 
-cdef herr_t walk_cb(unsigned int n, const H5E_error_t *desc, void *e) nogil noexcept:
+cdef herr_t walk_cb(unsigned int n, const H5E_error_t *desc, void *e) noexcept nogil:
 
     cdef err_data_t *ee = <err_data_t*>e
 
@@ -168,7 +168,7 @@ cdef err_cookie _error_handler  # Store 
 _error_handler.func = NULL
 _error_handler.data = NULL
 
-cdef void set_default_error_handler() nogil:
+cdef void set_default_error_handler() noexcept nogil:
     """Set h5py's current default error handler"""
     H5Eset_auto(<hid_t>H5E_DEFAULT, _error_handler.func, _error_handler.data)
 
