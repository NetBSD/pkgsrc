$NetBSD: patch-libkdcraw_libraw_src_libraw__cxx.cpp,v 1.1 2014/01/09 21:56:53 jperkin Exp $

SunOS bzero() needs strings.h

--- libkdcraw/libraw/src/libraw_cxx.cpp.orig	2009-05-10 11:25:49.000000000 +0000
+++ libkdcraw/libraw/src/libraw_cxx.cpp
@@ -9,6 +9,9 @@
 #include <errno.h>
 #include <float.h>
 #include <math.h>
+#ifdef __sun
+#include <strings.h>
+#endif
 #ifndef WIN32
 #include <netinet/in.h>
 #else
