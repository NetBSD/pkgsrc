$NetBSD: patch-mpi_mpi-inline.h,v 1.1 2011/07/13 21:21:52 adam Exp $

Change inline functions to static, which fixes building with Clang.

--- mpi/mpi-inline.h.orig	2011-07-13 21:09:51.000000000 +0000
+++ mpi/mpi-inline.h
@@ -29,7 +29,7 @@
 #define G10_MPI_INLINE_H
 
 #ifndef G10_MPI_INLINE_DECL
-#define G10_MPI_INLINE_DECL  extern __inline__
+#define G10_MPI_INLINE_DECL  static __inline__
 #endif
 
 G10_MPI_INLINE_DECL  mpi_limb_t
