$NetBSD: patch-src_mesa_drivers_dri_i965_brw__misc__state.c,v 1.1 2015/04/05 17:01:37 tnn Exp $

--- src/mesa/drivers/dri/i965/brw_misc_state.c.orig	2013-04-23 05:46:06.246006959 +0000
+++ src/mesa/drivers/dri/i965/brw_misc_state.c
@@ -223,6 +223,12 @@ static void emit_depthbuffer(struct brw_
    struct intel_region *hiz_region = depth_irb ? depth_irb->hiz_region : NULL;
    unsigned int len;
 
+   /* workaround for gen6, reserve enough space for HW workaround */
+   if (intel->gen == 6) {
+      if (intel_batchbuffer_space(intel) < 31*4)
+         intel_batchbuffer_flush(intel);
+   }
+
    /* 3DSTATE_DEPTH_BUFFER, 3DSTATE_STENCIL_BUFFER are both
     * non-pipelined state that will need the PIPE_CONTROL workaround.
     */
@@ -456,6 +462,12 @@ static void upload_polygon_stipple(struc
    if (!ctx->Polygon.StippleFlag)
       return;
 
+   /* workaround for gen6, reserve enough space for HW workaround */
+   if (intel->gen == 6) {
+      if (intel_batchbuffer_space(intel) < 41*4)
+         intel_batchbuffer_flush(intel);
+   }
+
    if (intel->gen == 6)
       intel_emit_post_sync_nonzero_flush(intel);
 
@@ -504,6 +516,12 @@ static void upload_polygon_stipple_offse
    if (!ctx->Polygon.StippleFlag)
       return;
 
+   /* workaround for gen6, reserve enough space for HW workaround */
+   if (intel->gen == 6) {
+      if (intel_batchbuffer_space(intel) < 10*4)
+         intel_batchbuffer_flush(intel);
+   }
+
    if (intel->gen == 6)
       intel_emit_post_sync_nonzero_flush(intel);
 
@@ -548,6 +566,12 @@ static void upload_aa_line_parameters(st
    if (!ctx->Line.SmoothFlag || !brw->has_aa_line_parameters)
       return;
 
+   /* workaround for gen6, reserve enough space for HW workaround */
+   if (intel->gen == 6) {
+      if (intel_batchbuffer_space(intel) < 11*4)
+         intel_batchbuffer_flush(intel);
+   }
+
    if (intel->gen == 6)
       intel_emit_post_sync_nonzero_flush(intel);
 
@@ -581,6 +605,12 @@ static void upload_line_stipple(struct b
    if (!ctx->Line.StippleFlag)
       return;
 
+   /* workaround for gen6, reserve enough space for HW workaround */
+   if (intel->gen == 6) {
+      if (intel_batchbuffer_space(intel) < 11*4)
+         intel_batchbuffer_flush(intel);
+   }
+
    if (intel->gen == 6)
       intel_emit_post_sync_nonzero_flush(intel);
 
@@ -612,8 +642,62 @@ static void upload_invarient_state( stru
    struct intel_context *intel = &brw->intel;
 
    /* 3DSTATE_SIP, 3DSTATE_MULTISAMPLE, etc. are nonpipelined. */
-   if (intel->gen == 6)
-      intel_emit_post_sync_nonzero_flush(intel);
+   if (intel->gen == 6) {
+      int i;
+
+      if (intel->batch.need_workaround_flush) {
+
+         BEGIN_BATCH(33);
+         OUT_BATCH(_3DSTATE_PIPE_CONTROL);
+         OUT_BATCH(PIPE_CONTROL_CS_STALL |
+	     PIPE_CONTROL_STALL_AT_SCOREBOARD);
+         OUT_BATCH(0); /* address */
+         OUT_BATCH(0); /* write data */
+
+         OUT_BATCH(_3DSTATE_PIPE_CONTROL);
+         OUT_BATCH(PIPE_CONTROL_WRITE_IMMEDIATE);
+         OUT_RELOC(intel->batch.workaround_bo,
+	     I915_GEM_DOMAIN_INSTRUCTION, I915_GEM_DOMAIN_INSTRUCTION, 0);
+         OUT_BATCH(0); /* write data */
+      } else
+	 BEGIN_BATCH(25);
+      /* Select the 3D pipeline (as opposed to media) */
+      OUT_BATCH(brw->CMD_PIPELINE_SELECT << 16 | 0);
+
+      OUT_BATCH(_3DSTATE_MULTISAMPLE << 16 | (1));
+      OUT_BATCH(MS_PIXEL_LOCATION_CENTER |
+                MS_NUMSAMPLES_1);
+      OUT_BATCH(0); /* positions for 4/8-sample */
+
+      OUT_BATCH(_3DSTATE_SAMPLE_MASK << 16 | (2 - 2));
+      OUT_BATCH(1);
+
+      if (intel->gen < 7) {
+         for (i = 0; i < 4; i++) {
+            OUT_BATCH(_3DSTATE_GS_SVB_INDEX << 16 | (4 - 2));
+            OUT_BATCH(i << SVB_INDEX_SHIFT);
+            OUT_BATCH(0);
+            OUT_BATCH(0xffffffff);
+         }
+      }
+
+      /* 0x61020000  State Instruction Pointer */
+      {
+         OUT_BATCH(CMD_STATE_INSN_POINTER);
+         OUT_BATCH(0);
+      }
+
+
+      {
+         OUT_BATCH(brw->CMD_VF_STATISTICS << 16 |
+            (unlikely(INTEL_DEBUG & DEBUG_STATS) ? 1 : 0));
+      }
+      ADVANCE_BATCH();
+
+      if (intel->batch.need_workaround_flush)
+         intel->batch.need_workaround_flush = false;
+
+   } else {
 
    {
       /* 0x61040000  Pipeline Select */
@@ -693,6 +777,7 @@ static void upload_invarient_state( stru
 
       BRW_BATCH_STRUCT(brw, &vfs);
    }
+   }
 }
 
 const struct brw_tracked_state brw_invarient_state = {
