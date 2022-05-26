$NetBSD: patch-scipy_spatial_ckdtree_src_ckdtree__decl.h,v 1.1 2022/05/26 14:49:59 tnn Exp $

Many errors like this:
scipy/spatial/ckdtree/src/query_pairs.cxx:110:16: error: argument to '__builtin_prefetch' must be a constant integer

--- scipy/spatial/ckdtree/src/ckdtree_decl.h.orig	2022-04-29 21:14:38.000000000 +0000
+++ scipy/spatial/ckdtree/src/ckdtree_decl.h
@@ -10,7 +10,11 @@
 #include <numpy/npy_common.h>
 #define CKDTREE_LIKELY(x) NPY_LIKELY(x)
 #define CKDTREE_UNLIKELY(x)  NPY_UNLIKELY(x)
+#if !defined(__clang__)
 #define CKDTREE_PREFETCH(x, rw, loc)  NPY_PREFETCH(x, rw, loc)
+#else
+#define CKDTREE_PREFETCH(x, rw, loc)
+#endif
 
 #define ckdtree_intp_t npy_intp
 #define ckdtree_isinf(x)   sc_isinf(x)
