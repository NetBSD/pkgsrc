$NetBSD: patch-Src___dotblas.c,v 1.1 2015/01/27 05:05:30 dbj Exp $

--- Src/_dotblas.c.orig	2006-07-24 20:11:35.000000000 +0000
+++ Src/_dotblas.c
@@ -12,7 +12,11 @@ static char module_doc[] =
 #include "Python.h"
 #include "libnumarray.h"
 #include "arrayobject.h"
+#ifdef __APPLE__
+#include <Accelerate/Accelerate.h>
+#else
 #include <cblas.h>
+#endif
 
 #include <stdio.h>
 
