$NetBSD: patch-scipy_spatial_ckdtree_src_ckdtree__decl.h,v 1.3 2023/05/05 14:59:25 adam Exp $

Many errors like this:
scipy/spatial/ckdtree/src/query_pairs.cxx:110:16: error: argument to '__builtin_prefetch' must be a constant integer

--- scipy/spatial/ckdtree/src/ckdtree_decl.h.orig	1970-01-01 00:00:00.000000000 +0000
+++ scipy/spatial/ckdtree/src/ckdtree_decl.h
@@ -9,7 +9,11 @@
 #include <numpy/npy_common.h>
 #define CKDTREE_LIKELY(x) NPY_LIKELY(x)
 #define CKDTREE_UNLIKELY(x)  NPY_UNLIKELY(x)
+#if 0
 #define CKDTREE_PREFETCH(x, rw, loc)  NPY_PREFETCH(x, rw, loc)
+#else
+#define CKDTREE_PREFETCH(x, rw, loc)
+#endif
 
 #define ckdtree_intp_t npy_intp
 #define ckdtree_fmin(x, y)   fmin(x, y)
