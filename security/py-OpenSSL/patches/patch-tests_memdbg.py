$NetBSD: patch-tests_memdbg.py,v 1.1 2017/01/28 12:09:14 wiz Exp $

Fix running test on NetBSD.
Breaks Linux, but I expect more people to run the tests on NetBSD.
https://github.com/pyca/pyopenssl/issues/595

--- tests/memdbg.py.orig	2016-02-15 10:25:58.000000000 +0000
+++ tests/memdbg.py
@@ -18,16 +18,16 @@ _ffi.cdef(
 
     int  CRYPTO_set_mem_functions(void *(*m)(size_t),void *(*r)(void *,size_t), void (*f)(void *));
 
-    int backtrace(void **buffer, int size);
-    char **backtrace_symbols(void *const *buffer, int size);
-    void backtrace_symbols_fd(void *const *buffer, int size, int fd);
+    size_t backtrace(void **buffer, size_t size);
+    char **backtrace_symbols(void *const *buffer, size_t size);
+    void backtrace_symbols_fd(void *const *buffer, size_t size, int fd);
     """)  # noqa
 _api = _ffi.verify(
     """
     #include <openssl/crypto.h>
     #include <stdlib.h>
     #include <execinfo.h>
-    """, libraries=["crypto"])
+    """, libraries=["crypto", "execinfo"])
 C = _ffi.dlopen(None)
 
 verbose = False
