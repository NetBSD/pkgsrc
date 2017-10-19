$NetBSD: patch-source_fitz_load-jpx.c,v 1.6 2017/10/19 20:32:07 leot Exp $

- Restrict OPJ_STATIC to Windows (avoid linking errors due to hidden symbols)

- MuPDF does some locking around its allocation calls; it overrides openjpeg's
  allocators to do this locking too. However mupdf tries to manually align things
  in a way that doesn't match what openjpeg does, which we noticed when frees
  were segfaulting because the addresses didn't match up.

  In the case of the openjpeg port it's relying on malloc(3)'s guarantee
  "The allocated space is suitably aligned (after possible pointer coercion)
  for storage of any type of object" so patch mupdf to do the same.

  Fixes crash noticed by jca@ in https://www.broadband-forum.org/technical/download/TR-177.pdf

  From OpenBSD ports textproc/mupdf/patch-source_fitz_load-jpx_c,v 1.5.

--- source/fitz/load-jpx.c.orig	2017-04-05 11:02:21.000000000 +0000
+++ source/fitz/load-jpx.c
@@ -444,7 +444,9 @@ fz_load_jpx_info(fz_context *ctx, unsign
 
 #else /* HAVE_LURATECH */
 
+#if defined(_WIN32) || defined(_WIN64)
 #define OPJ_STATIC
+#endif
 #define OPJ_HAVE_INTTYPES_H
 #if !defined(_WIN32) && !defined(_WIN64)
 #define OPJ_HAVE_STDINT_H
@@ -554,30 +556,14 @@ void opj_free(void *ptr)
 
 void * opj_aligned_malloc(size_t size)
 {
-	uint8_t *ptr;
-	int off;
-
-	if (size == 0)
-		return NULL;
 
-	size += 16 + sizeof(uint8_t);
-	ptr = opj_malloc(size);
-	if (ptr == NULL)
-		return NULL;
-	off = 16-(((int)(intptr_t)ptr) & 15);
-	ptr[off-1] = off;
-	return ptr + off;
+	return opj_malloc(size);
 }
 
 void opj_aligned_free(void* ptr_)
 {
-	uint8_t *ptr = (uint8_t *)ptr_;
-	uint8_t off;
-	if (ptr == NULL)
-		return;
-
-	off = ptr[-1];
-	opj_free((void *)(((unsigned char *)ptr) - off));
+	
+	opj_free(ptr_);
 }
 
 #if 0
