$NetBSD: patch-src_mesa_drivers_dri_i965_gen6__wm__state.c,v 1.1 2015/04/05 17:01:37 tnn Exp $

--- src/mesa/drivers/dri/i965/gen6_wm_state.c.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/mesa/drivers/dri/i965/gen6_wm_state.c
@@ -102,15 +102,14 @@ upload_wm_state(struct brw_context *brw)
     /* CACHE_NEW_WM_PROG */
    if (brw->wm.prog_data->nr_params == 0) {
       /* Disable the push constant buffers. */
-      BEGIN_BATCH(5);
+      BEGIN_BATCH(14);
       OUT_BATCH(_3DSTATE_CONSTANT_PS << 16 | (5 - 2));
       OUT_BATCH(0);
       OUT_BATCH(0);
       OUT_BATCH(0);
       OUT_BATCH(0);
-      ADVANCE_BATCH();
    } else {
-      BEGIN_BATCH(5);
+      BEGIN_BATCH(14);
       OUT_BATCH(_3DSTATE_CONSTANT_PS << 16 |
 		GEN6_CONSTANT_BUFFER_0_ENABLE |
 		(5 - 2));
@@ -123,7 +122,6 @@ upload_wm_state(struct brw_context *brw)
       OUT_BATCH(0);
       OUT_BATCH(0);
       OUT_BATCH(0);
-      ADVANCE_BATCH();
    }
 
    dw2 = dw4 = dw5 = dw6 = 0;
@@ -183,7 +181,6 @@ upload_wm_state(struct brw_context *brw)
    dw6 |= brw_count_bits(brw->fragment_program->Base.InputsRead) <<
       GEN6_WM_NUM_SF_OUTPUTS_SHIFT;
 
-   BEGIN_BATCH(9);
    OUT_BATCH(_3DSTATE_WM << 16 | (9 - 2));
    OUT_BATCH(brw->wm.prog_offset);
    OUT_BATCH(dw2);
