$NetBSD: patch-mpi_mpi-inline.h,v 1.1 2012/11/07 12:23:24 wiz Exp $

From 5093bed27580e608de073bcc5953bd76b6b8b2de Mon Sep 17 00:00:00 2001
From: Werner Koch <wk@gnupg.org>
Date: Tue, 6 Nov 2012 17:14:04 +0100
Subject: [PATCH] Fix extern inline use for gcc > 4.3 in c99 mode

* mpi/mpi-inline.h [!G10_MPI_INLINE_DECL]: Take care of changed extern
inline semantics in gcc.

--- mpi/mpi-inline.h.orig	2012-01-20 10:51:16.000000000 +0000
+++ mpi/mpi-inline.h
@@ -28,8 +28,15 @@
 #ifndef G10_MPI_INLINE_H
 #define G10_MPI_INLINE_H

+/* Starting with gcc 4.3 "extern inline" conforms in c99 mode to the
+   c99 semantics.  To keep the useful old semantics we use an
+   attribute.  */
 #ifndef G10_MPI_INLINE_DECL
-#define G10_MPI_INLINE_DECL  extern __inline__
+# ifdef __GNUC_STDC_INLINE__
+#  define G10_MPI_INLINE_DECL  extern inline __attribute__ ((__gnu_inline__))
+# else
+#  define G10_MPI_INLINE_DECL  extern __inline__
+# endif
 #endif

 G10_MPI_INLINE_DECL  mpi_limb_t
