$NetBSD: patch-h5py_h5fd.pyx,v 1.1 2023/12/13 20:29:09 wiz Exp $

Fix build with Cython 3.
https://github.com/h5py/h5py/pull/2345

--- h5py/h5fd.pyx.orig	2023-10-05 11:57:54.000000000 +0000
+++ h5py/h5fd.pyx
@@ -144,10 +144,10 @@ cdef herr_t H5FD_fileobj_close(H5FD_file
     stdlib_free(f)
     return 0
 
-cdef haddr_t H5FD_fileobj_get_eoa(const H5FD_fileobj_t *f, H5FD_mem_t type):
+cdef haddr_t H5FD_fileobj_get_eoa(const H5FD_fileobj_t *f, H5FD_mem_t type) noexcept nogil:
     return f.eoa
 
-cdef herr_t H5FD_fileobj_set_eoa(H5FD_fileobj_t *f, H5FD_mem_t type, haddr_t addr):
+cdef herr_t H5FD_fileobj_set_eoa(H5FD_fileobj_t *f, H5FD_mem_t type, haddr_t addr) noexcept nogil:
     f.eoa = addr
     return 0
 
@@ -191,22 +191,38 @@ cdef herr_t H5FD_fileobj_flush(H5FD_file
 cdef H5FD_class_t info
 memset(&info, 0, sizeof(info))
 
+# Cython doesn't support "except X" in casting definition currently
+ctypedef herr_t (*file_free_func_ptr)(void *) except -1
+
+ctypedef herr_t (*file_close_func_ptr)(H5FD_t *) except -1
+ctypedef haddr_t (*file_get_eoa_func_ptr)(const H5FD_t *, H5FD_mem_t) noexcept
+ctypedef herr_t (*file_set_eof_func_ptr)(H5FD_t *, H5FD_mem_t, haddr_t) noexcept
+ctypedef haddr_t (*file_get_eof_func_ptr)(const H5FD_t *, H5FD_mem_t) except -1
+ctypedef herr_t (*file_read_func_ptr)(H5FD_t *, H5FD_mem_t, hid_t, haddr_t, size_t, void*) except -1
+ctypedef herr_t (*file_write_func_ptr)(H5FD_t *, H5FD_mem_t, hid_t, haddr_t, size_t, const void*) except -1
+ctypedef herr_t (*file_truncate_func_ptr)(H5FD_t *, hid_t, hbool_t) except -1
+ctypedef herr_t (*file_flush_func_ptr)(H5FD_t *, hid_t, hbool_t) except -1
+
+
 info.name = 'fileobj'
 info.maxaddr = libc.stdint.SIZE_MAX - 1
 info.fc_degree = H5F_CLOSE_WEAK
 info.fapl_size = sizeof(PyObject *)
 info.fapl_get = <void *(*)(H5FD_t *)>H5FD_fileobj_fapl_get
 info.fapl_copy = <void *(*)(const void *)>H5FD_fileobj_fapl_copy
-info.fapl_free = <herr_t (*)(void *)>H5FD_fileobj_fapl_free
+
+info.fapl_free = <file_free_func_ptr>H5FD_fileobj_fapl_free
+
 info.open = <H5FD_t *(*)(const char *name, unsigned flags, hid_t fapl, haddr_t maxaddr)>H5FD_fileobj_open
-info.close = <herr_t (*)(H5FD_t *)>H5FD_fileobj_close
-info.get_eoa = <haddr_t (*)(const H5FD_t *, H5FD_mem_t)>H5FD_fileobj_get_eoa
-info.set_eoa = <herr_t (*)(H5FD_t *, H5FD_mem_t, haddr_t)>H5FD_fileobj_set_eoa
-info.get_eof = <haddr_t (*)(const H5FD_t *, H5FD_mem_t)>H5FD_fileobj_get_eof
-info.read = <herr_t (*)(H5FD_t *, H5FD_mem_t, hid_t, haddr_t, size_t, void *)>H5FD_fileobj_read
-info.write = <herr_t (*)(H5FD_t *, H5FD_mem_t, hid_t, haddr_t, size_t, const void *)>H5FD_fileobj_write
-info.truncate = <herr_t (*)(H5FD_t *, hid_t, hbool_t)>H5FD_fileobj_truncate
-info.flush = <herr_t (*)(H5FD_t *, hid_t, hbool_t)>H5FD_fileobj_flush
+
+info.close = <file_close_func_ptr>H5FD_fileobj_close
+info.get_eoa = <file_get_eoa_func_ptr>H5FD_fileobj_get_eoa
+info.set_eoa = <file_set_eof_func_ptr>H5FD_fileobj_set_eoa
+info.get_eof = <file_get_eof_func_ptr>H5FD_fileobj_get_eof
+info.read = <file_read_func_ptr>H5FD_fileobj_read
+info.write = <file_write_func_ptr>H5FD_fileobj_write
+info.truncate = <file_truncate_func_ptr>H5FD_fileobj_truncate
+info.flush = <file_flush_func_ptr>H5FD_fileobj_flush
 # H5FD_FLMAP_DICHOTOMY
 info.fl_map = [H5FD_MEM_SUPER,  # default
                H5FD_MEM_SUPER,  # super
