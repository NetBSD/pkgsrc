$NetBSD: patch-src_src_prefix.cpp,v 1.1 2016/06/16 02:28:51 kamil Exp $

Unbreak build on NetBSD. Stop redefining NULL as an arbitrary value.

--- src/src/prefix.cpp.orig	2016-01-23 16:43:04.000000000 +0000
+++ src/src/prefix.cpp
@@ -55,9 +55,6 @@ extern "C" {
 #endif /* __cplusplus */
 
 
-#undef NULL
-#define NULL ((void *) 0)
-
 #ifdef __GNUC__
 	#define br_return_val_if_fail(expr,val) if (!(expr)) {fprintf (stderr, "** BinReloc (%s): assertion %s failed\n", __PRETTY_FUNCTION__, #expr); return val;}
 #else
