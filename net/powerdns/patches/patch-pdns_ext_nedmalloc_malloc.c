$NetBSD: patch-pdns_ext_nedmalloc_malloc.c,v 1.1 2012/05/20 19:37:49 marino Exp $

--- pdns/ext/nedmalloc/malloc.c.orig	2012-05-20 19:21:21.401620000 +0000
+++ pdns/ext/nedmalloc/malloc.c
@@ -1213,7 +1213,8 @@ int mspace_mallopt(int, int);
 #ifndef LACKS_UNISTD_H
 #include <unistd.h>     /* for sbrk */
 #else /* LACKS_UNISTD_H */
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) \
+ && !defined(__DragonFly__)
 extern void*     sbrk(ptrdiff_t);
 #endif /* FreeBSD etc */
 #endif /* LACKS_UNISTD_H */
