$NetBSD: patch-src_apsw.c,v 1.1 2023/10/02 15:54:46 abs Exp $

alloca.h has been deprecated for a long time, and no modern system
should need it (and some do not even have it). While there are some
references to alloca() in the source, none are in src/apsw.c

Fixes build on at least NetBSD

https://github.com/rogerbinns/apsw/pull/490

--- src/apsw.c.orig	2023-09-13 14:34:08.000000000 +0000
+++ src/apsw.c
@@ -101,8 +101,6 @@ API Reference
 #include <stdarg.h>
 #ifdef _MSC_VER
 #include <malloc.h>
-#else
-#include <alloca.h>
 #endif
 
 /* Get the version number */
