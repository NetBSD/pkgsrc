$NetBSD: patch-src_libw32dll_wine_registry.c,v 1.4 2017/08/02 03:41:35 maya Exp $

everyone can have sys/stat.h

--- src/libw32dll/wine/registry.c.orig	2014-05-29 11:11:59.000000000 +0000
+++ src/libw32dll/wine/registry.c
@@ -22,9 +22,7 @@
 #include <basedir.h>
 #endif
 
-#ifdef __DragonFly__
 #include <sys/stat.h>
-#endif
 
 //#undef TRACE
 //#define TRACE printf
