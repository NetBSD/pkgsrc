$NetBSD: patch-src_3rdparty_opennurbs_opennurbs__zlib.h,v 1.1 2017/12/18 21:21:44 plunky Exp $

don't provide own zlib

--- src/3rdparty/opennurbs/opennurbs_zlib.h.orig	2017-12-18 11:43:25.553865013 +0000
+++ src/3rdparty/opennurbs/opennurbs_zlib.h
@@ -30,7 +30,7 @@
 
 #if !defined(Z_PREFIX)
 /* decorates zlib functions with a "z_" prefix to prevent symbol collision. */
-#define Z_PREFIX
+//#define Z_PREFIX
 #endif
 
 #if !defined(MY_ZCALLOC)
@@ -38,7 +38,7 @@
 //#define MY_ZCALLOC
 #endif
 
-#include "./zlib/zlib.h"
+#include <zlib.h>
 
 ON_BEGIN_EXTERNC
 voidpf zcalloc (voidpf, unsigned, unsigned);
