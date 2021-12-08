$NetBSD: patch-src_powerpc_ffi__powerpc.h,v 1.2 2021/12/08 08:20:17 adam Exp $

Workaround for ILP32 powerpc, which doesn't have 128-bit-length data types.

--- src/powerpc/ffi_powerpc.h.orig	2021-06-27 15:17:08.000000000 +0000
+++ src/powerpc/ffi_powerpc.h
@@ -57,6 +57,7 @@ typedef union
   double d;
 } ffi_dblfl;
 
+#ifdef POWERPC64
 #if defined(__FLOAT128_TYPE__) && defined(__HAVE_FLOAT128)
 typedef _Float128 float128;
 #elif defined(__FLOAT128__)
@@ -64,6 +65,7 @@ typedef __float128 float128;
 #else
 typedef char float128[16] __attribute__((aligned(16)));
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
