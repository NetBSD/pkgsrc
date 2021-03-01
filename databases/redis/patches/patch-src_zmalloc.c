$NetBSD: patch-src_zmalloc.c,v 1.1 2021/03/01 13:19:19 adam Exp $

Fix compile errors with no HAVE_MALLOC_SIZE.
https://github.com/redis/redis/pull/8533/files

--- src/zmalloc.c.orig	2021-03-01 13:13:04.000000000 +0000
+++ src/zmalloc.c
@@ -32,6 +32,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <unistd.h>
+#include <assert.h>
 
 /* This function provide us access to the original libc free(). This is useful
  * for instance to free results obtained by backtrace_symbols(). We need
@@ -49,18 +50,14 @@ void zlibc_free(void *ptr) {
 
 #ifdef HAVE_MALLOC_SIZE
 #define PREFIX_SIZE (0)
+#define ASSERT_NO_SIZE_OVERFLOW(sz)
 #else
 #if defined(__sun) || defined(__sparc) || defined(__sparc__)
 #define PREFIX_SIZE (sizeof(long long))
 #else
 #define PREFIX_SIZE (sizeof(size_t))
 #endif
-#endif
-
-#if PREFIX_SIZE > 0
 #define ASSERT_NO_SIZE_OVERFLOW(sz) assert((sz) + PREFIX_SIZE > (sz))
-#else
-#define ASSERT_NO_SIZE_OVERFLOW(sz)
 #endif
 
 /* Explicitly override malloc/free etc when using tcmalloc. */
