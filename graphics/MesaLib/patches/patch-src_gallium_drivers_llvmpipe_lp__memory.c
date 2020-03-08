$NetBSD: patch-src_gallium_drivers_llvmpipe_lp__memory.c,v 1.1 2020/03/08 10:35:03 tnn Exp $

Force the symbol into data rather than bss to work around linking
problem on OS X.

Undefined symbols for architecture x86_64:
  "_lp_dummy_tile", referenced from:
      _lp_rast_create in libllvmpipe.a(lp_rast.c.o)
      _llvmpipe_launch_grid in libllvmpipe.a(lp_state_cs.c.o)
      _lp_setup_set_fragment_sampler_views in libllvmpipe.a(lp_setup.c.o)

--- src/gallium/drivers/llvmpipe/lp_memory.c.orig	2020-03-05 21:34:31.000000000 +0000
+++ src/gallium/drivers/llvmpipe/lp_memory.c
@@ -32,5 +32,9 @@
 /* A single dummy tile used in a couple of out-of-memory situations. 
  */
 PIPE_ALIGN_VAR(LP_MIN_VECTOR_ALIGN)
+#ifdef __APPLE__
+uint8_t lp_dummy_tile[TILE_SIZE * TILE_SIZE * 4] = { 0 };
+#else
 uint8_t lp_dummy_tile[TILE_SIZE * TILE_SIZE * 4];
+#endif
 
