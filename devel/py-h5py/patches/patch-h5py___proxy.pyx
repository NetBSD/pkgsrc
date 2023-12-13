$NetBSD: patch-h5py___proxy.pyx,v 1.1 2023/12/13 20:29:09 wiz Exp $

Fix build with Cython 3.
https://github.com/h5py/h5py/pull/2345

--- h5py/_proxy.pyx.orig	2023-10-04 09:21:14.000000000 +0000
+++ h5py/_proxy.pyx
@@ -241,7 +241,7 @@ ctypedef struct h5py_scatter_t:
     void* buf
 
 cdef herr_t h5py_scatter_cb(void* elem, hid_t type_id, unsigned ndim,
-                const hsize_t *point, void *operator_data) nogil except -1:
+                const hsize_t *point, void *operator_data) except -1 nogil:
     cdef h5py_scatter_t* info = <h5py_scatter_t*>operator_data
 
     memcpy(elem, (<char*>info[0].buf)+((info[0].i)*(info[0].elsize)),
@@ -252,7 +252,7 @@ cdef herr_t h5py_scatter_cb(void* elem, 
     return 0
 
 cdef herr_t h5py_gather_cb(void* elem, hid_t type_id, unsigned ndim,
-                const hsize_t *point, void *operator_data) nogil except -1:
+                const hsize_t *point, void *operator_data) except -1 nogil:
     cdef h5py_scatter_t* info = <h5py_scatter_t*>operator_data
 
     memcpy((<char*>info[0].buf)+((info[0].i)*(info[0].elsize)), elem,
