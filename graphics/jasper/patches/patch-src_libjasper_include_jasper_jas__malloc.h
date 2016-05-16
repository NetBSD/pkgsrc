$NetBSD: patch-src_libjasper_include_jasper_jas__malloc.h,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/include/jasper/jas_malloc.h.orig	2007-01-19 21:43:04.000000000 +0000
+++ src/libjasper/include/jasper/jas_malloc.h
@@ -95,6 +95,9 @@ extern "C" {
 #define	jas_free	MEMFREE
 #define	jas_realloc	MEMREALLOC
 #define	jas_calloc	MEMCALLOC
+#define jas_alloc2(a, b)	MEMALLOC((a)*(b))
+#define jas_alloc3(a, b, c)	MEMALLOC((a)*(b)*(c))
+#define jas_realloc2(p, a, b)	MEMREALLOC((p), (a)*(b))
 #endif
 
 /******************************************************************************\
@@ -115,6 +118,12 @@ void *jas_realloc(void *ptr, size_t size
 /* Allocate a block of memory and initialize the contents to zero. */
 void *jas_calloc(size_t nmemb, size_t size);
 
+/* size-checked double allocation .*/
+void *jas_alloc2(size_t, size_t);
+
+void *jas_alloc3(size_t, size_t, size_t);
+
+void *jas_realloc2(void *, size_t, size_t);
 #endif
 
 #ifdef __cplusplus
