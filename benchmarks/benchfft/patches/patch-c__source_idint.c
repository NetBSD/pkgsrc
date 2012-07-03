$NetBSD: patch-c__source_idint.c,v 1.1 2012/07/03 18:19:17 joerg Exp $

--- c_source/idint.c.orig	2012-07-03 12:50:05.000000000 +0000
+++ c_source/idint.c
@@ -7,6 +7,7 @@ typedef FFTW_REAL real;
     The author retains the right to distribute this software freely, but
     is not responsible for it's quality or maintainance. */
 
+void
 idint(x, length, wtab)
 real *x, *wtab;
 int length;
