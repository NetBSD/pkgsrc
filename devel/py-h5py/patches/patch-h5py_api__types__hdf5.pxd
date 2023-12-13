$NetBSD: patch-h5py_api__types__hdf5.pxd,v 1.1 2023/12/13 20:29:09 wiz Exp $

Fix build with Cython 3.
https://github.com/h5py/h5py/pull/2345

--- h5py/api_types_hdf5.pxd.orig	2023-10-09 14:16:30.000000000 +0000
+++ h5py/api_types_hdf5.pxd
@@ -257,27 +257,27 @@ cdef extern from "hdf5.h":
       herr_t  (*sb_encode)(H5FD_t *file, char *name, unsigned char *p)
       herr_t  (*sb_decode)(H5FD_t *f, const char *name, const unsigned char *p)
       size_t  fapl_size
-      void *  (*fapl_get)(H5FD_t *file)
-      void *  (*fapl_copy)(const void *fapl)
-      herr_t  (*fapl_free)(void *fapl)
+      void *  (*fapl_get)(H5FD_t *file) except *
+      void *  (*fapl_copy)(const void *fapl) except *
+      herr_t  (*fapl_free)(void *fapl) except -1
       size_t  dxpl_size
       void *  (*dxpl_copy)(const void *dxpl)
       herr_t  (*dxpl_free)(void *dxpl)
-      H5FD_t *(*open)(const char *name, unsigned flags, hid_t fapl, haddr_t maxaddr)
-      herr_t  (*close)(H5FD_t *file)
+      H5FD_t *(*open)(const char *name, unsigned flags, hid_t fapl, haddr_t maxaddr) except *
+      herr_t  (*close)(H5FD_t *file) except -1
       int     (*cmp)(const H5FD_t *f1, const H5FD_t *f2)
       herr_t  (*query)(const H5FD_t *f1, unsigned long *flags)
       herr_t  (*get_type_map)(const H5FD_t *file, H5FD_mem_t *type_map)
       haddr_t (*alloc)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl_id, hsize_t size)
       herr_t  (*free)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl_id, haddr_t addr, hsize_t size)
-      haddr_t (*get_eoa)(const H5FD_t *file, H5FD_mem_t type)
-      herr_t  (*set_eoa)(H5FD_t *file, H5FD_mem_t type, haddr_t addr)
-      haddr_t (*get_eof)(const H5FD_t *file, H5FD_mem_t type)
+      haddr_t (*get_eoa)(const H5FD_t *file, H5FD_mem_t type) noexcept
+      herr_t  (*set_eoa)(H5FD_t *file, H5FD_mem_t type, haddr_t addr) noexcept
+      haddr_t (*get_eof)(const H5FD_t *file, H5FD_mem_t type) except -1
       herr_t  (*get_handle)(H5FD_t *file, hid_t fapl, void**file_handle)
-      herr_t  (*read)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl, haddr_t addr, size_t size, void *buffer)
-      herr_t  (*write)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl, haddr_t addr, size_t size, const void *buffer)
-      herr_t  (*flush)(H5FD_t *file, hid_t dxpl_id, hbool_t closing)
-      herr_t  (*truncate)(H5FD_t *file, hid_t dxpl_id, hbool_t closing)
+      herr_t  (*read)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl, haddr_t addr, size_t size, void *buffer) except *
+      herr_t  (*write)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl, haddr_t addr, size_t size, const void *buffer) except *
+      herr_t  (*flush)(H5FD_t *file, hid_t dxpl_id, hbool_t closing) except -1
+      herr_t  (*truncate)(H5FD_t *file, hid_t dxpl_id, hbool_t closing) except -1
       herr_t  (*lock)(H5FD_t *file, hbool_t rw)
       herr_t  (*unlock)(H5FD_t *file)
       H5FD_mem_t fl_map[<int>H5FD_MEM_NTYPES]
@@ -295,27 +295,27 @@ cdef extern from "hdf5.h":
       herr_t  (*sb_encode)(H5FD_t *file, char *name, unsigned char *p)
       herr_t  (*sb_decode)(H5FD_t *f, const char *name, const unsigned char *p)
       size_t  fapl_size
-      void *  (*fapl_get)(H5FD_t *file)
-      void *  (*fapl_copy)(const void *fapl)
-      herr_t  (*fapl_free)(void *fapl)
+      void *  (*fapl_get)(H5FD_t *file) except *
+      void *  (*fapl_copy)(const void *fapl) except *
+      herr_t  (*fapl_free)(void *fapl) except -1
       size_t  dxpl_size
       void *  (*dxpl_copy)(const void *dxpl)
       herr_t  (*dxpl_free)(void *dxpl)
-      H5FD_t *(*open)(const char *name, unsigned flags, hid_t fapl, haddr_t maxaddr)
-      herr_t  (*close)(H5FD_t *file)
+      H5FD_t *(*open)(const char *name, unsigned flags, hid_t fapl, haddr_t maxaddr) except *
+      herr_t  (*close)(H5FD_t *file) except -1
       int     (*cmp)(const H5FD_t *f1, const H5FD_t *f2)
       herr_t  (*query)(const H5FD_t *f1, unsigned long *flags)
       herr_t  (*get_type_map)(const H5FD_t *file, H5FD_mem_t *type_map)
       haddr_t (*alloc)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl_id, hsize_t size)
       herr_t  (*free)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl_id, haddr_t addr, hsize_t size)
-      haddr_t (*get_eoa)(const H5FD_t *file, H5FD_mem_t type)
-      herr_t  (*set_eoa)(H5FD_t *file, H5FD_mem_t type, haddr_t addr)
-      haddr_t (*get_eof)(const H5FD_t *file, H5FD_mem_t type)
+      haddr_t (*get_eoa)(const H5FD_t *file, H5FD_mem_t type) noexcept
+      herr_t  (*set_eoa)(H5FD_t *file, H5FD_mem_t type, haddr_t addr) noexcept
+      haddr_t (*get_eof)(const H5FD_t *file, H5FD_mem_t type) except -1
       herr_t  (*get_handle)(H5FD_t *file, hid_t fapl, void**file_handle)
-      herr_t  (*read)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl, haddr_t addr, size_t size, void *buffer)
-      herr_t  (*write)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl, haddr_t addr, size_t size, const void *buffer)
-      herr_t  (*flush)(H5FD_t *file, hid_t dxpl_id, hbool_t closing)
-      herr_t  (*truncate)(H5FD_t *file, hid_t dxpl_id, hbool_t closing)
+      herr_t  (*read)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl, haddr_t addr, size_t size, void *buffer) except *
+      herr_t  (*write)(H5FD_t *file, H5FD_mem_t type, hid_t dxpl, haddr_t addr, size_t size, const void *buffer) except *
+      herr_t  (*flush)(H5FD_t *file, hid_t dxpl_id, hbool_t closing) except -1
+      herr_t  (*truncate)(H5FD_t *file, hid_t dxpl_id, hbool_t closing) except -1
       herr_t  (*lock)(H5FD_t *file, hbool_t rw)
       herr_t  (*unlock)(H5FD_t *file)
       H5FD_mem_t fl_map[<int>H5FD_MEM_NTYPES]
