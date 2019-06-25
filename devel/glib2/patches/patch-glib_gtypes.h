$NetBSD: patch-glib_gtypes.h,v 1.1 2019/06/25 10:57:28 prlw1 Exp $

We insist on C99, so size_t exists => use it.
PR pkg/54298

--- glib/gtypes.h.orig	2019-06-10 17:47:20.000000000 +0000
+++ glib/gtypes.h
@@ -57,6 +57,9 @@ typedef unsigned int    guint;
 typedef float   gfloat;
 typedef double  gdouble;
 
+typedef size_t  gsize;
+typedef ssize_t gssize;
+
 /* Define min and max constants for the fixed size numerical types */
 /**
  * G_MININT8: (value -128)
