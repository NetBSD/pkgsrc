$NetBSD: patch-src_libw32dll_wine_registry.c,v 1.1 2012/05/18 18:53:31 marino Exp $

--- src/libw32dll/wine/registry.c.orig	2012-02-04 00:41:43.000000000 +0000
+++ src/libw32dll/wine/registry.c
@@ -22,6 +22,10 @@
 #include <basedir.h>
 #endif
 
+#ifdef __DragonFly__
+#include <sys/stat.h>
+#endif
+
 //#undef TRACE
 //#define TRACE printf
 
