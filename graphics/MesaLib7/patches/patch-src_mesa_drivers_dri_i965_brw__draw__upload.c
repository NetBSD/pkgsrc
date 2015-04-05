$NetBSD: patch-src_mesa_drivers_dri_i965_brw__draw__upload.c,v 1.1 2015/04/05 17:01:37 tnn Exp $

--- src/mesa/drivers/dri/i965/brw_draw_upload.c.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/mesa/drivers/dri/i965/brw_draw_upload.c
@@ -531,8 +531,14 @@ static void brw_emit_vertices(struct brw
    struct intel_context *intel = intel_context(ctx);
    GLuint i;
 
+   /* workaround for gen6, reserve enough space for HW workaround */
+   if (intel->gen == 6) {
+	if (intel_batchbuffer_space(intel) < (13 + 4*brw->vb.nr_buffers + 2* brw->vb.nr_enabled)*4)
+	    intel_batchbuffer_flush(intel);
+   }
    brw_emit_query_begin(brw);
 
+
    /* If the VS doesn't read any inputs (calculating vertex position from
     * a state variable for some reason, for example), emit a single pad
     * VERTEX_ELEMENT struct and bail.
