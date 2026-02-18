$NetBSD: patch-src_pip.c,v 1.1 2026/02/18 10:39:42 wiz Exp $

Calloc/Free are gone, use standard functions.

--- src/pip.c.orig	2022-06-11 18:30:18.000000000 +0000
+++ src/pip.c
@@ -42,7 +42,7 @@ SEXP R_point_in_polygon_mt(SEXP px, SEXP py, SEXP polx
 	SEXP ret;
 
 	pol.lines = LENGTH(polx); /* check later that first == last */
-	pol.p = (PLOT_POINT *) Calloc(pol.lines, PLOT_POINT); /* Calloc does error handling */
+	pol.p = (PLOT_POINT *) calloc(pol.lines, sizeof(PLOT_POINT));
 	for (i = 0; i < LENGTH(polx); i++) {
 		pol.p[i].x = NUMERIC_POINTER(polx)[i];
 		pol.p[i].y = NUMERIC_POINTER(poly)[i];
@@ -70,7 +70,7 @@ For each query point q, InPoly returns one of four cha
 			default: INTEGER_POINTER(ret)[i] = -1; break;
 		}
 	}
-	Free(pol.p);
+	free(pol.p);
 	return(ret);
 }
 
