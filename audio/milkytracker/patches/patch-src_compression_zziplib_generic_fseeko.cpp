$NetBSD: patch-src_compression_zziplib_generic_fseeko.cpp,v 1.2 2012/03/15 20:16:24 hans Exp $

--- src/compression/zziplib/generic/fseeko.cpp.orig	2008-01-05 17:33:45.000000000 +0000
+++ src/compression/zziplib/generic/fseeko.cpp
@@ -52,13 +52,8 @@
 #include <zzip___mmap.h>
 #include <zzip___fnmatch.h>
 
-#if __STDC_VERSION__+0 > 199900L
-#define ___
-#define ____
-#else
 #define ___ {
 #define ____ }
-#endif
 
 #ifndef ZZIP_HAVE_FSEEKO
 #define fseeko fseek
