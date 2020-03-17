$NetBSD: patch-lib_malloc_malloc.c,v 1.1 2020/03/17 17:09:48 rillig Exp $

Fix array subscript with char index.

--- lib/malloc/malloc.c.orig	2018-06-20 13:55:09.000000000 +0000
+++ lib/malloc/malloc.c
@@ -266,7 +266,7 @@ static const unsigned long binsizes[NBUC
 };
 
 /* binsizes[x] == (1 << ((x) + 3)) */
-#define binsize(x)	binsizes[(x)]
+#define binsize(x)	binsizes[(size_t) (x)]
 
 #if !defined (errno)
 extern int errno;
