$NetBSD: patch-libkdcraw_libraw_libraw_libraw__alloc.h,v 1.1 2014/01/09 21:56:53 jperkin Exp $

SunOS bzero() needs strings.h

--- libkdcraw/libraw/libraw/libraw_alloc.h.orig	2009-05-10 11:25:49.000000000 +0000
+++ libkdcraw/libraw/libraw/libraw_alloc.h
@@ -26,6 +26,9 @@
 
 #include <stdlib.h>
 #include <string.h>
+#ifdef __sun
+#include <strings.h>
+#endif
 #ifdef WIN32
 #define bzero(p,sz) memset(p,0,sz)
 #endif
