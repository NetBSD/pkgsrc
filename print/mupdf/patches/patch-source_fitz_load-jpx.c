$NetBSD: patch-source_fitz_load-jpx.c,v 1.10 2020/05/07 20:42:57 leot Exp $

- MuPDF does some locking around its allocation calls; it overrides openjpeg's
  allocators to do this locking too. However mupdf tries to manually align things
  in a way that doesn't match what openjpeg does, which we noticed when frees
  were segfaulting because the addresses didn't match up.

  In the case of the openjpeg port it's relying on malloc(3)'s guarantee
  "The allocated space is suitably aligned (after possible pointer coercion)
  for storage of any type of object" so patch mupdf to do the same.

  Fixes crash noticed by jca@ in https://www.broadband-forum.org/technical/download/TR-177.pdf

  From OpenBSD ports textproc/mupdf/patch-source_fitz_load-jpx_c,v 1.5.

--- source/fitz/load-jpx.c.orig	2020-05-05 11:29:09.000000000 +0000
+++ source/fitz/load-jpx.c
@@ -584,19 +584,7 @@ void opj_free(void *ptr)
 
 static void * opj_aligned_malloc_n(size_t alignment, size_t size)
 {
-	uint8_t *ptr;
-	size_t off;
-
-	if (size == 0)
-		return NULL;
-
-	size += alignment + sizeof(uint8_t);
-	ptr = opj_malloc(size);
-	if (ptr == NULL)
-		return NULL;
-	off = alignment-(((int)(intptr_t)ptr) & (alignment - 1));
-	ptr[off-1] = (uint8_t)off;
-	return ptr + off;
+	return opj_malloc(size);
 }
 
 void * opj_aligned_malloc(size_t size)
@@ -611,13 +599,7 @@ void * opj_aligned_32_malloc(size_t size
 
 void opj_aligned_free(void* ptr_)
 {
-	uint8_t *ptr = (uint8_t *)ptr_;
-	uint8_t off;
-	if (ptr == NULL)
-		return;
-
-	off = ptr[-1];
-	opj_free((void *)(((unsigned char *)ptr) - off));
+	opj_free(ptr_);
 }
 
 #if 0
