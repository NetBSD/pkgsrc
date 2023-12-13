$NetBSD: patch-h5py___locks.pxi,v 1.1 2023/12/13 20:29:09 wiz Exp $

Fix build with Cython 3.
https://github.com/h5py/h5py/pull/2345

--- h5py/_locks.pxi.orig	2021-05-09 11:55:36.000000000 +0000
+++ h5py/_locks.pxi
@@ -63,7 +63,7 @@ cdef class FastRLock:
         return self._owner == pythread.PyThread_get_thread_ident()
 
 
-cdef inline bint lock_lock(FastRLock lock, long current_thread, bint blocking) nogil:
+cdef inline bint lock_lock(FastRLock lock, long current_thread, bint blocking) noexcept nogil:
     # Note that this function *must* hold the GIL when being called.
     # We just use 'nogil' in the signature to make sure that no Python
     # code execution slips in that might free the GIL
@@ -83,7 +83,7 @@ cdef inline bint lock_lock(FastRLock loc
         lock, current_thread,
         pythread.WAIT_LOCK if blocking else pythread.NOWAIT_LOCK)
 
-cdef bint _acquire_lock(FastRLock lock, long current_thread, int wait) nogil:
+cdef bint _acquire_lock(FastRLock lock, long current_thread, int wait) noexcept nogil:
     # Note that this function *must* hold the GIL when being called.
     # We just use 'nogil' in the signature to make sure that no Python
     # code execution slips in that might free the GIL
@@ -111,7 +111,7 @@ cdef bint _acquire_lock(FastRLock lock, 
     lock._count = 1
     return 1
 
-cdef inline void unlock_lock(FastRLock lock) nogil:
+cdef inline void unlock_lock(FastRLock lock) noexcept nogil:
     # Note that this function *must* hold the GIL when being called.
     # We just use 'nogil' in the signature to make sure that no Python
     # code execution slips in that might free the GIL
