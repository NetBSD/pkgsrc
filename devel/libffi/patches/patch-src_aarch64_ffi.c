$NetBSD: patch-src_aarch64_ffi.c,v 1.1 2020/02/28 22:37:24 tnn Exp $

For closures, aarch64 needs explicit invalidation of the code segments
i-cache after data is written through the data mapping.
But we don't have any way to look up the address of the code segment
right now so for now skip doing the cache flush.

--- src/aarch64/ffi.c.orig	2019-10-31 14:49:54.000000000 +0000
+++ src/aarch64/ffi.c
@@ -808,7 +808,8 @@ ffi_prep_closure_loc (ffi_closure *closu
   ffi_clear_cache(tramp, tramp + FFI_TRAMPOLINE_SIZE);
 
   /* Also flush the cache for code mapping.  */
-#ifdef _M_ARM64
+#if defined(_M_ARM64) || defined(__NetBSD__)
+  // ffi_data_to_code_pointer is broken on NetBSD
   // Not using dlmalloc.c for Windows ARM64 builds
   // so calling ffi_data_to_code_pointer() isn't necessary
   unsigned char *tramp_code = tramp;
