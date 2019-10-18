$NetBSD: patch-src_gallium_drivers_radeonsi_si__state__shaders.c,v 1.2 2019/10/18 09:57:07 nia Exp $

#if'out some debug code on SunOS. There is no open_memstream(3)

--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2019-10-09 16:52:00.000000000 +0000
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -2113,12 +2113,14 @@ static void si_build_shader_variant(stru
 	}
 
 	if (shader->compiler_ctx_state.is_debug_context) {
+#if defined(HAVE_OPEN_MEMSTREAM)
 		FILE *f = open_memstream(&shader->shader_log,
 					 &shader->shader_log_size);
 		if (f) {
 			si_shader_dump(sscreen, shader, NULL, f, false);
 			fclose(f);
 		}
+#endif
 	}
 
 	si_shader_init_pm4_state(sscreen, shader);
