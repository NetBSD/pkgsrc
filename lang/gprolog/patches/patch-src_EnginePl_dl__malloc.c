$NetBSD: patch-src_EnginePl_dl__malloc.c,v 1.1 2019/06/14 17:30:13 maya Exp $

(from editors/emacs20):
Work around bug in gcc 5.x that makes calloc into a call to itself,
resulting in an infinite loop.

--- src/EnginePl/dl_malloc.c.orig	2013-04-15 07:24:10.000000000 +0000
+++ src/EnginePl/dl_malloc.c
@@ -4773,6 +4773,10 @@ void* dlcalloc(size_t n_elements, size_t
       req = MAX_SIZE_T; /* force downstream failure on overflow */
   }
   mem = dlmalloc(req);
+#ifdef __GNUC__
+/* Work around a gcc bug that converts calloc into a call to itself. */
+  __asm volatile("" : "+r" (mem));
+#endif
   if (mem != 0 && calloc_must_clear(mem2chunk(mem)))
     memset(mem, 0, req);
   return mem;
