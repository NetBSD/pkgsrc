$NetBSD: patch-src_3rdparty_opennurbs_opennurbs__zlib.h,v 1.2 2025/03/16 14:56:12 plunky Exp $

don't provide zlib, use pkgsrc version

--- src/3rdparty/opennurbs/opennurbs_zlib.h.orig	2025-02-20 12:25:22.000000000 +0000
+++ src/3rdparty/opennurbs/opennurbs_zlib.h
@@ -30,7 +30,6 @@
 
 #if !defined(Z_PREFIX)
 /* decorates zlib functions with a "z_" prefix to prevent symbol collision. */
-#define Z_PREFIX
 #endif
 
 #if !defined(MY_ZCALLOC)
@@ -39,7 +38,7 @@
 #endif
 
 extern "C" {
-#include "./zlib/zlib.h"
+#include <zlib.h>
 }
 
 ON_BEGIN_EXTERNC
