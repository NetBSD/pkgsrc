$NetBSD: patch-src_LibRaw_libraw_libraw__alloc.h,v 1.2 2011/08/25 14:42:53 jakllsch Exp $

Work around redefined symbol.

--- src/external/LibRaw/libraw/libraw_alloc.h.orig	2011-08-24 09:20:29.000000000 +0000
+++ src/external/LibRaw/libraw/libraw_alloc.h
@@ -27,6 +27,7 @@ it under the terms of the one of three l
 
 #ifdef __cplusplus
 
+#undef MSIZE
 #define MSIZE 32
 
 class DllDef libraw_memmgr
