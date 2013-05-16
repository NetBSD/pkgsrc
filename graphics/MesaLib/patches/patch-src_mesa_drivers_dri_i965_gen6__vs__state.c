$NetBSD: patch-src_mesa_drivers_dri_i965_gen6__vs__state.c,v 1.1 2013/05/16 05:22:02 richard Exp $

--- src/mesa/drivers/dri/i965/gen6_vs_state.c.orig	2011-11-23 01:09:52.000000000 +0000
+++ src/mesa/drivers/dri/i965/gen6_vs_state.c
@@ -120,6 +120,12 @@ upload_vs_state(struct brw_context *brw)
 {
    struct intel_context *intel = &brw->intel;
 
+   /* workaround for gen6, reserve enough space for HW workaround */
+   if (intel->gen == 6) {
+       if (intel_batchbuffer_space(intel) < 23*4)
+           intel_batchbuffer_flush(intel);
+   }
+
    if (brw->vs.push_const_size == 0) {
       /* Disable the push constant buffers. */
       BEGIN_BATCH(5);
