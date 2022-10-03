$NetBSD: patch-lib_malloc_malloc.c,v 1.3 2022/10/03 12:50:27 wiz Exp $

Fix array subscript with char index.

https://lists.gnu.org/archive/html/bug-bash/2020-03/msg00056.html

--- lib/malloc/malloc.c.orig	2022-04-18 16:37:56.000000000 +0000
+++ lib/malloc/malloc.c
@@ -299,7 +299,7 @@ static const unsigned long binsizes[NBUC
 };
 
 /* binsizes[x] == (1 << ((x) + 5)) */
-#define binsize(x)	binsizes[(x)]
+#define binsize(x)	binsizes[(size_t) (x)]
 
 #define MAXALLOC_SIZE	binsizes[NBUCKETS-1]
 
