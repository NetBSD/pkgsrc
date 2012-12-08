$NetBSD: patch-src_LibRaw_libraw_libraw__alloc.h,v 1.3 2012/12/08 00:15:26 jakllsch Exp $

Work around redefined symbol.

--- src/external/LibRaw/libraw/libraw_alloc.h.orig	2012-11-23 23:23:21.000000000 +0000
+++ src/external/LibRaw/libraw/libraw_alloc.h
@@ -27,6 +27,7 @@ it under the terms of the one of three l
 
 #ifdef __cplusplus
 
+#undef MSIZE
 #define MSIZE 32
 
 class DllDef libraw_memmgr
