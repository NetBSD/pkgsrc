$NetBSD: patch-source_blender_blenkernel_intern_CCGSubSurf__legacy.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/blenkernel/intern/CCGSubSurf_legacy.cc.orig	2024-06-05 11:47:56.000000000 +0000
+++ source/blender/blenkernel/intern/CCGSubSurf_legacy.cc
@@ -6,6 +6,8 @@
  * \ingroup bke
  */
 
+#include <stdlib.h> /* for alloca() */
+
 #include "BLI_sys_types.h" /* for intptr_t support */
 #include "MEM_guardedalloc.h"
 
