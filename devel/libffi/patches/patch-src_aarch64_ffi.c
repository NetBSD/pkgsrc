$NetBSD: patch-src_aarch64_ffi.c,v 1.4 2022/09/26 18:43:48 adam Exp $

For closures, aarch64 needs explicit invalidation of the code segments
i-cache after data is written through the data mapping.
But we don't have any way to look up the address of the code segment
right now so for now skip doing the cache flush.

--- src/aarch64/ffi.c.orig	2022-09-19 09:57:23.000000000 +0000
+++ src/aarch64/ffi.c
@@ -869,7 +869,8 @@ ffi_prep_closure_loc (ffi_closure *closu
   ffi_clear_cache(tramp, tramp + FFI_TRAMPOLINE_SIZE);
 
   /* Also flush the cache for code mapping.  */
-# ifdef _WIN32
+# if defined(_WIN32) || defined(__NetBSD__)
+  // ffi_data_to_code_pointer is broken on NetBSD
   // Not using dlmalloc.c for Windows ARM64 builds
   // so calling ffi_data_to_code_pointer() isn't necessary
   unsigned char *tramp_code = tramp;
