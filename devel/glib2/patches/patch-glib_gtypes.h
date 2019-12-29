$NetBSD: patch-glib_gtypes.h,v 1.4 2019/12/29 19:40:56 triaxx Exp $

We insist on C99, so size_t exists => use it.
PR pkg/54298
Include <sys/types.h> for ssize_t definition on at least OS X 10.14.

--- glib/gtypes.h.orig	2019-12-19 16:33:15.000000000 +0000
+++ glib/gtypes.h
@@ -32,6 +32,7 @@
 #include <glibconfig.h>
 #include <glib/gmacros.h>
 #include <glib/gversionmacros.h>
+#include <sys/types.h>
 #include <time.h>
 
 G_BEGIN_DECLS
@@ -56,6 +57,9 @@ typedef unsigned int    guint;
 
 typedef float   gfloat;
 typedef double  gdouble;
+
+typedef size_t  gsize;
+typedef ssize_t gssize;
 
 /* Define min and max constants for the fixed size numerical types */
 /**
