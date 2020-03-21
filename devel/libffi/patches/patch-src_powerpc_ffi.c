$NetBSD: patch-src_powerpc_ffi.c,v 1.1 2020/03/21 16:08:34 rin Exp $

Workaround for ILP32 powerpc, which doesn't have 128-bit-length data types.

--- src/powerpc/ffi.c.orig	2019-11-18 20:35:19.000000000 +0900
+++ src/powerpc/ffi.c	2020-03-22 00:26:32.702408263 +0900
@@ -87,7 +87,11 @@ ffi_call_int (ffi_cif *cif,
      For ELFv2 ABI, use a bounce buffer for homogeneous structs too,
      for similar reasons. This bounce buffer must be aligned to 16
      bytes for use with homogeneous structs of vectors (float128).  */
+#ifdef POWERPC64
   float128 smst_buffer[8];
+#else
+  __int64_t smst_buffer[16];
+#endif
   extended_cif ecif;
 
   ecif.cif = cif;
