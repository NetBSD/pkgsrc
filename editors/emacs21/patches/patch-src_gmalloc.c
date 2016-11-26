$NetBSD: patch-src_gmalloc.c,v 1.1 2016/11/26 04:22:40 dholland Exp $

Work around bug in gcc 5.x that makes calloc into a call to itself,
resulting in an infinite loop.

--- src/gmalloc.c.orig	2001-11-04 17:35:43.000000000 +0000
+++ src/gmalloc.c
@@ -1520,7 +1520,13 @@ calloc (nmemb, size)
      register __malloc_size_t nmemb;
      register __malloc_size_t size;
 {
-  register __ptr_t result = malloc (nmemb * size);
+  register __ptr_t result;
+
+  result = malloc (nmemb * size);
+#ifdef __GNUC__
+/* Work around a gcc bug that converts calloc into a call to itself. */
+  __asm volatile("" : "+r" (result));
+#endif
 
   if (result != NULL)
     (void) memset (result, 0, nmemb * size);
