$NetBSD: patch-storage_tokudb_ft-index_portability_toku__portability.h,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- storage/tokudb/ft-index/portability/toku_portability.h.orig	2015-02-13 12:07:05.000000000 +0000
+++ storage/tokudb/ft-index/portability/toku_portability.h
@@ -187,7 +187,7 @@ int      creat(const char *pathname, mod
 int      fstat(int fd, struct stat *buf)            __attribute__((__deprecated__));
 int      stat(const char *path, struct stat *buf)   __attribute__((__deprecated__));
 int      getpid(void)                               __attribute__((__deprecated__));
-#    if defined(__FreeBSD__) || defined(__APPLE__)
+#    if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 int syscall(int __sysno, ...)             __attribute__((__deprecated__));
 #    else
 long int syscall(long int __sysno, ...)             __attribute__((__deprecated__));
@@ -200,7 +200,7 @@ int      _dup2(int fd, int fd2)         
 #undef strdup
 #    if defined(__FreeBSD__)
 char*    strdup(const char *)         __malloc_like __attribute__((__deprecated__));
-#    elif defined(__APPLE__)
+#    elif defined(__APPLE__) || defined(__NetBSD__)
 char*    strdup(const char *)         __attribute__((__deprecated__));
 #    else
 char*    strdup(const char *)         __THROW __attribute_malloc__ __nonnull ((1)) __attribute__((__deprecated__));
@@ -216,7 +216,7 @@ ssize_t  pwrite(int, const void *, size_
 extern void *malloc(size_t)                    __malloc_like __attribute__((__deprecated__));
 extern void free(void*)                        __attribute__((__deprecated__));
 extern void *realloc(void*, size_t)            __malloc_like __attribute__((__deprecated__));
-#     elif defined(__APPLE__)
+#     elif defined(__APPLE__) || defined(__NetBSD__)
 extern void *malloc(size_t)                    __attribute__((__deprecated__));
 extern void free(void*)                        __attribute__((__deprecated__));
 extern void *realloc(void*, size_t)            __attribute__((__deprecated__));
