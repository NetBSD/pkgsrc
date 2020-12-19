$NetBSD: patch-tests_memdbg.py,v 1.3 2020/12/19 11:52:26 leot Exp $

Fix running test on NetBSD.
https://github.com/pyca/pyopenssl/issues/595

--- tests/memdbg.py.orig	2020-12-15 15:30:54.000000000 +0000
+++ tests/memdbg.py
@@ -19,9 +19,9 @@ _ffi.cdef(
     int  CRYPTO_set_mem_functions(
         void *(*m)(size_t),void *(*r)(void *,size_t), void (*f)(void *));
 
-    int backtrace(void **buffer, int size);
-    char **backtrace_symbols(void *const *buffer, int size);
-    void backtrace_symbols_fd(void *const *buffer, int size, int fd);
+    size_t backtrace(void **buffer, size_t size);
+    char **backtrace_symbols(void *const *buffer, size_t size);
+    void backtrace_symbols_fd(void *const *buffer, size_t size, int fd);
     """
 )  # noqa
 _api = _ffi.verify(
@@ -30,7 +30,7 @@ _api = _ffi.verify(
     #include <stdlib.h>
     #include <execinfo.h>
     """,
-    libraries=["crypto"],
+    libraries=["crypto", "execinfo"] if sys.platform.startswith('netbsd') else ["crypto"],
 )
 C = _ffi.dlopen(None)
 
