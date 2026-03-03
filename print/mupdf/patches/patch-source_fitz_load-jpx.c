$NetBSD: patch-source_fitz_load-jpx.c,v 1.11 2026/03/03 21:49:01 yhardy Exp $

- MuPDF does some locking around its allocation calls; it overrides openjpeg's
  allocators to do this locking too. However mupdf tries to manually align things
  in a way that doesn't match what openjpeg does, which we noticed when frees
  were segfaulting because the addresses didn't match up.

  In the case of the openjpeg port it's relying on malloc(3)'s guarantee
  "The allocated space is suitably aligned (after possible pointer coercion)
  for storage of any type of object" so patch mupdf to do the same.

  Fixes crash noticed by jca@ in https://www.broadband-forum.org/technical/download/TR-177.pdf

  From OpenBSD ports textproc/mupdf/patch-source_fitz_load-jpx_c,v 1.5.

--- source/fitz/load-jpx.c.orig	2026-02-18 16:24:19.000000000 +0000
+++ source/fitz/load-jpx.c
@@ -163,19 +163,7 @@ static void * fz_opj_aligned_malloc_n(size_t alignment
 
 static void * fz_opj_aligned_malloc_n(size_t alignment, size_t size)
 {
-	uint8_t *ptr;
-	size_t off;
-
-	if (size == 0)
-		return NULL;
-
-	size += alignment + sizeof(uint8_t);
-	ptr = fz_opj_malloc(size);
-	if (ptr == NULL)
-		return NULL;
-	off = alignment-(((int)(intptr_t)ptr) & (alignment - 1));
-	ptr[off-1] = (uint8_t)off;
-	return ptr + off;
+	return fz_opj_malloc(size);
 }
 
 void * fz_opj_aligned_malloc(size_t size)
@@ -190,13 +178,7 @@ void fz_opj_aligned_free(void* ptr_)
 
 void fz_opj_aligned_free(void* ptr_)
 {
-	uint8_t *ptr = (uint8_t *)ptr_;
-	uint8_t off;
-	if (ptr == NULL)
-		return;
-
-	off = ptr[-1];
-	fz_opj_free((void *)(((unsigned char *)ptr) - off));
+	fz_opj_free(ptr_);
 }
 
 #if 0
