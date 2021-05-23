$NetBSD: patch-storage_tokudb_PerconaFT_portability_toku__portability.h,v 1.1 2021/05/23 15:32:47 nia Exp $

Use proper attribute syntax on SunOS.

--- storage/tokudb/PerconaFT/portability/toku_portability.h.orig	2015-02-25 15:40:56.000000000 +0000
+++ storage/tokudb/PerconaFT/portability/toku_portability.h
@@ -200,7 +200,7 @@ int      _dup2(int fd, int fd2)
 #undef strdup
 #    if defined(__FreeBSD__)
 char*    strdup(const char *)         __malloc_like __attribute__((__deprecated__));
-#    elif defined(__APPLE__)
+#    elif defined(__APPLE__) || defined(__sun)
 char*    strdup(const char *)         __attribute__((__deprecated__));
 #    else
 char*    strdup(const char *)         __THROW __attribute_malloc__ __nonnull ((1)) __attribute__((__deprecated__));
@@ -216,7 +216,7 @@ ssize_t  pwrite(int, const void *, size_
 extern void *malloc(size_t)                    __malloc_like __attribute__((__deprecated__));
 extern void free(void*)                        __attribute__((__deprecated__));
 extern void *realloc(void*, size_t)            __malloc_like __attribute__((__deprecated__));
-#     elif defined(__APPLE__)
+#     elif defined(__APPLE__) || defined(__sun)
 extern void *malloc(size_t)                    __attribute__((__deprecated__));
 extern void free(void*)                        __attribute__((__deprecated__));
 extern void *realloc(void*, size_t)            __attribute__((__deprecated__));
