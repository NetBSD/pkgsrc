$NetBSD: patch-goffice_math_go-matrix.c,v 1.1 2015/08/10 19:30:06 joerg Exp $

Format string is passed in as argument.

--- goffice/math/go-matrix.c.orig	2015-08-10 16:26:04.000000000 +0000
+++ goffice/math/go-matrix.c
@@ -581,6 +581,8 @@ SUFFIX(go_quad_matrix_eigen_range) (cons
 	}
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 
 void
 SUFFIX(go_quad_matrix_dump) (const QMATRIX *A, const char *fmt)
@@ -594,6 +596,8 @@ SUFFIX(go_quad_matrix_dump) (const QMATR
 	}
 }
 
+#pragma GCC diagnostic pop
+
 /* -------------------------------------------------------------------------- */
 
 /**
