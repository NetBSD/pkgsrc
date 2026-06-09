$NetBSD: patch-goffice_math_go-matrix.c,v 1.2 2026/06/09 17:35:16 wiz Exp $

Format string is passed in as argument.

--- goffice/math/go-matrix.c.orig	2026-04-30 00:44:54.000000000 +0000
+++ goffice/math/go-matrix.c
@@ -566,6 +566,8 @@ SUFFIX(go_quad_matrix_eigen_range) (const QMATRIX *A,
 	}
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 
 /**
  * go_quad_matrix_dump: (skip)
@@ -587,6 +589,8 @@ SUFFIX(go_quad_matrix_dump) (const QMATRIX *A, const c
 		g_printerr ("\n");
 	}
 }
+
+#pragma GCC diagnostic pop
 
 /* -------------------------------------------------------------------------- */
 
