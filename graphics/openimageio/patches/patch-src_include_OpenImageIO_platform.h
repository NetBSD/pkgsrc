$NetBSD: patch-src_include_OpenImageIO_platform.h,v 1.1 2016/02/17 21:54:09 richard Exp $

SunOS needs <alloca.h> for alloca()

--- src/include/OpenImageIO/platform.h.orig	2015-06-11 17:25:58.000000000 +0000
+++ src/include/OpenImageIO/platform.h
@@ -91,7 +91,9 @@
 #define OIIO_CPLUSPLUS11 1
 #endif
 
-
+#ifdef __sun
+#include <alloca.h>
+#endif
 
 /// allocates memory, equivalent of C99 type var_name[size]
 #define OIIO_ALLOCA(type, size) ((type*)alloca((size) * sizeof (type)))
