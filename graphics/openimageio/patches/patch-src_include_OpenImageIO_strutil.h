$NetBSD: patch-src_include_OpenImageIO_strutil.h,v 1.1 2018/10/07 23:38:45 ryoon Exp $

--- src/include/OpenImageIO/strutil.h.orig	2018-10-01 21:26:14.000000000 +0000
+++ src/include/OpenImageIO/strutil.h
@@ -41,6 +41,8 @@
 #ifndef OPENIMAGEIO_STRUTIL_H
 #define OPENIMAGEIO_STRUTIL_H
 
+#include <stdarg.h>
+
 #include <string>
 #include <cstdio>
 #include <vector>
