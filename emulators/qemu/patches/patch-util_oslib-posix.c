$NetBSD: patch-util_oslib-posix.c,v 1.1 2018/01/04 16:48:17 gson Exp $

Check for posix_memalign in configure script instead of incorrectly
testing _POSIX_C_SOURCE in util/oslib-posix.c

--- util/oslib-posix.c.orig	2017-12-13 17:27:20.000000000 +0000
+++ util/oslib-posix.c
@@ -105,7 +105,7 @@ void *qemu_try_memalign(size_t alignment
         alignment = sizeof(void*);
     }
 
-#if defined(_POSIX_C_SOURCE) && !defined(__sun__)
+#if defined(CONFIG_POSIX_MEMALIGN)
     int ret;
     ret = posix_memalign(&ptr, alignment, size);
     if (ret != 0) {
