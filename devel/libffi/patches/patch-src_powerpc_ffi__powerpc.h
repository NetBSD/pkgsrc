$NetBSD: patch-src_powerpc_ffi__powerpc.h,v 1.1 2020/03/21 16:08:34 rin Exp $

Workaround for ILP32 powerpc, which doesn't have 128-bit-length data types.

--- src/powerpc/ffi_powerpc.h.orig	2019-11-18 20:35:19.000000000 +0900
+++ src/powerpc/ffi_powerpc.h	2020-03-22 00:31:24.149783131 +0900
@@ -57,6 +57,7 @@ typedef union
   double d;
 } ffi_dblfl;
 
+#ifdef POWERPC64
 #if defined(__FLOAT128_TYPE__)
 typedef _Float128 float128;
 #elif defined(__FLOAT128__)
@@ -64,6 +65,7 @@ typedef __float128 float128;
 #else
 typedef __int128 float128;
 #endif
+#endif /* POWERPC64 */
 
 void FFI_HIDDEN ffi_closure_SYSV (void);
 void FFI_HIDDEN ffi_go_closure_sysv (void);
@@ -97,9 +99,11 @@ ffi_status FFI_HIDDEN ffi_prep_closure_l
 						    void (*) (ffi_cif *, void *,
 							      void **, void *),
 						    void *, void *);
+#ifdef POWERPC64
 int FFI_HIDDEN ffi_closure_helper_LINUX64 (ffi_cif *,
 					   void (*) (ffi_cif *, void *,
 						     void **, void *),
 					   void *, void *,
 					   unsigned long *, ffi_dblfl *,
 					   float128 *);
+#endif
