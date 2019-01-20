$NetBSD: patch-src_gallium_drivers_radeonsi_si__state__shaders.c,v 1.3 2019/01/20 09:50:28 tnn Exp $

#if'out some debug code on SunOS. There is no open_memstream(3)

--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2019-01-17 11:26:22.000000000 +0000
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -1721,12 +1721,14 @@ static void si_build_shader_variant(stru
 	}
 
 	if (shader->compiler_ctx_state.is_debug_context) {
+#if defined(HAVE_OPEN_MEMSTREAM)
 		FILE *f = open_memstream(&shader->shader_log,
 					 &shader->shader_log_size);
 		if (f) {
 			si_shader_dump(sscreen, shader, NULL, sel->type, f, false);
 			fclose(f);
 		}
+#endif
 	}
 
 	si_shader_init_pm4_state(sscreen, shader);
