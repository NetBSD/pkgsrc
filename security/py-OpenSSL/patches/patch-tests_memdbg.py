$NetBSD: patch-tests_memdbg.py,v 1.4 2023/10/26 06:32:57 adam Exp $

Fix running test on NetBSD.
https://github.com/pyca/pyopenssl/issues/595

--- tests/memdbg.py.orig	2023-10-19 22:18:27.000000000 +0000
+++ tests/memdbg.py
@@ -17,9 +17,9 @@ _ffi.cdef(
     int  CRYPTO_set_mem_functions(
         void *(*m)(size_t),void *(*r)(void *,size_t), void (*f)(void *));
 
-    int backtrace(void **buffer, int size);
-    char **backtrace_symbols(void *const *buffer, int size);
-    void backtrace_symbols_fd(void *const *buffer, int size, int fd);
+    size_t backtrace(void **buffer, size_t size);
+    char **backtrace_symbols(void *const *buffer, size_t size);
+    void backtrace_symbols_fd(void *const *buffer, size_t size, int fd);
     """
 )
 _api = _ffi.verify(
@@ -28,7 +28,7 @@ _api = _ffi.verify(
     #include <stdlib.h>
     #include <execinfo.h>
     """,
-    libraries=["crypto"],
+    libraries=["crypto", "execinfo"] if sys.platform.startswith('netbsd') else ["crypto"],
 )
 C = _ffi.dlopen(None)
 
