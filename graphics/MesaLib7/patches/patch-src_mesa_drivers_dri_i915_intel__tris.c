$NetBSD: patch-src_mesa_drivers_dri_i915_intel__tris.c,v 1.1 2015/04/05 17:01:37 tnn Exp $

--- src/mesa/drivers/dri/i915/intel_tris.c.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/mesa/drivers/dri/i915/intel_tris.c
@@ -337,7 +337,7 @@ void intel_finish_vb(struct intel_contex
  *                    Emit primitives as inline vertices               *
  ***********************************************************************/
 
-#ifdef __i386__
+#if (defined(i386) || defined(__i386__)) && !(defined(__SOLARIS__) || defined(sun))
 #define COPY_DWORDS( j, vb, vertsize, v )			\
 do {								\
    int __tmp;							\
