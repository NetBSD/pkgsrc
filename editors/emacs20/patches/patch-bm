$NetBSD: patch-bm,v 1.4 2011/12/01 05:12:57 dholland Exp $

- use standard headers
- fix type of __malloc_extra_blocks
- add an empty asm() destroying memory that prevents gcc from
  optimizing out __malloc_hook and friends (which leads to
  SIGSEGV in temacs during build)

--- src/alloc.c.orig	1999-09-16 07:20:15.000000000 +0000
+++ src/alloc.c
@@ -53,12 +53,13 @@ extern char *sbrk ();
 
 #if defined (__STDC__) && __STDC__
 #include <stddef.h>
+#include <stdlib.h>
 #define	__malloc_size_t		size_t
 #else
 #define	__malloc_size_t		unsigned int
 #endif
 extern __malloc_size_t _bytes_used;
-extern int __malloc_extra_blocks;
+extern __malloc_size_t __malloc_extra_blocks;
 #endif /* !defined(DOUG_LEA_MALLOC) */
 
 #define max(A,B) ((A) > (B) ? (A) : (B))
@@ -380,6 +381,9 @@ emacs_blocked_free (ptr)
 {
   BLOCK_INPUT;
   __free_hook = old_free_hook;
+#ifdef __GNUC__
+  __asm __volatile("":::"memory");
+#endif
   free (ptr);
   /* If we released our reserve (due to running out of memory),
      and we have a fair amount free once again,
@@ -420,6 +424,9 @@ emacs_blocked_malloc (size)
 
   BLOCK_INPUT;
   __malloc_hook = old_malloc_hook;
+#ifdef __GNUC__
+  __asm __volatile("":::"memory");
+#endif
 #ifdef DOUG_LEA_MALLOC
     mallopt (M_TOP_PAD, malloc_hysteresis * 4096);
 #else
@@ -441,6 +448,9 @@ emacs_blocked_realloc (ptr, size)
 
   BLOCK_INPUT;
   __realloc_hook = old_realloc_hook;
+#ifdef __GNUC__
+  __asm __volatile("":::"memory");
+#endif
   value = (void *) realloc (ptr, size);
   __realloc_hook = emacs_blocked_realloc;
   UNBLOCK_INPUT;
