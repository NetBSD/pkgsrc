$NetBSD: patch-src_mesa_drivers_dri_i965_intel__batchbuffer.c,v 1.1 2015/04/05 17:01:37 tnn Exp $

--- src/mesa/drivers/dri/i965/intel_batchbuffer.c.orig	2011-10-15 04:29:59.000000000 +0000
+++ src/mesa/drivers/dri/i965/intel_batchbuffer.c
@@ -427,8 +427,10 @@ intel_batchbuffer_emit_mi_flush(struct i
 	 OUT_BATCH(PIPE_CONTROL_INSTRUCTION_FLUSH |
 		   PIPE_CONTROL_WRITE_FLUSH |
 		   PIPE_CONTROL_DEPTH_CACHE_FLUSH |
+		   PIPE_CONTROL_VF_CACHE_INVALIDATE |
 		   PIPE_CONTROL_TC_FLUSH |
-		   PIPE_CONTROL_NO_WRITE);
+		   PIPE_CONTROL_NO_WRITE |
+		   PIPE_CONTROL_CS_STALL);
 	 OUT_BATCH(0); /* write address */
 	 OUT_BATCH(0); /* write data */
 	 ADVANCE_BATCH();
