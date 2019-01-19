$NetBSD: patch-src_gallium_drivers_radeonsi_si__state__shaders.c,v 1.1 2019/01/19 17:47:51 tnn Exp $

#if'out some debug code on SunOS. There is no open_memstream(3)

--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2019-01-17 11:26:22.000000000 +0000
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -1721,6 +1721,7 @@ static void si_build_shader_variant(stru
 	}
 
 	if (shader->compiler_ctx_state.is_debug_context) {
+#if !defined(__sun)
 		FILE *f = open_memstream(&shader->shader_log,
 					 &shader->shader_log_size);
 		if (f) {
@@ -1728,6 +1729,7 @@ static void si_build_shader_variant(stru
 			fclose(f);
 		}
 	}
+#endif
 
 	si_shader_init_pm4_state(sscreen, shader);
 }
