$NetBSD: patch-c__source_dintime.c,v 1.1 2012/07/03 18:19:17 joerg Exp $

--- c_source/dintime.c.orig	2012-07-03 12:47:39.000000000 +0000
+++ c_source/dintime.c
@@ -16,6 +16,7 @@ struct complex { real r,i; };
 
 void dint(struct complex *, int, real *);
 
+void
 dintime( x, length, wtab )
 struct complex *x;
 int length;
