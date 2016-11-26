$NetBSD: patch-bi,v 1.2 2016/11/26 03:50:16 dholland Exp $

Work around bug in gcc 5.x that makes calloc into a call to itself,
resulting in an infinite loop.

--- src/gmalloc.c.orig	2000-02-21 13:21:51.000000000 +0000
+++ src/gmalloc.c
@@ -371,7 +371,7 @@ __malloc_size_t _bytes_free;
 /* Are you experienced?  */
 int __malloc_initialized;
 
-__malloc_size_t __malloc_extra_blocks;
+__malloc_size_t __malloc_extra_blocks = 0;
 
 void (*__malloc_initialize_hook) PP ((void));
 void (*__after_morecore_hook) PP ((void));
@@ -1420,7 +1420,13 @@ calloc (nmemb, size)
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
