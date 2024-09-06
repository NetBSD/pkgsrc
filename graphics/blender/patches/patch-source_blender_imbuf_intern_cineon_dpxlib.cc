$NetBSD: patch-source_blender_imbuf_intern_cineon_dpxlib.cc,v 1.1 2024/09/06 15:43:28 prlw1 Exp $

dpxlib.h is apparently a C header file, so alter the C++ file which includes it.

--- source/blender/imbuf/intern/cineon/dpxlib.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/imbuf/intern/cineon/dpxlib.cc
@@ -24,6 +24,8 @@
 
 #include "MEM_guardedalloc.h"
 
+using std::isnan;
+
 /*
  * For debug purpose
  */
