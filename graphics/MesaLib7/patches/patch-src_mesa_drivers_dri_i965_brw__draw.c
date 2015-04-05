$NetBSD: patch-src_mesa_drivers_dri_i965_brw__draw.c,v 1.1 2015/04/05 17:01:37 tnn Exp $

--- src/mesa/drivers/dri/i965/brw_draw.c.orig	2013-04-23 05:46:06.246377394 +0000
+++ src/mesa/drivers/dri/i965/brw_draw.c
@@ -168,7 +168,7 @@ static void brw_emit_prim(struct brw_con
     * and missed flushes of the render cache as it heads to other parts of
     * the besides the draw code.
     */
-   if (intel->always_flush_cache) {
+   if ((intel->always_flush_cache) || (intel->gen == 6)) {
       intel_batchbuffer_emit_mi_flush(intel);
    }
 
@@ -185,7 +185,7 @@ static void brw_emit_prim(struct brw_con
 
    intel->batch.need_workaround_flush = true;
 
-   if (intel->always_flush_cache) {
+   if ((intel->always_flush_cache) || (intel->gen == 6)) {
       intel_batchbuffer_emit_mi_flush(intel);
    }
 }
