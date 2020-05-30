$NetBSD: patch-gfx_drivers__context_sdl__gl__ctx.c,v 1.1 2020/05/30 14:26:52 nia Exp $

SDL supports GLSL.  Unbreaks menus using shaders.

--- gfx/drivers_context/sdl_gl_ctx.c.orig	2020-05-27 18:11:31.000000000 +0000
+++ gfx/drivers_context/sdl_gl_ctx.c
@@ -407,6 +407,8 @@ static uint32_t sdl_ctx_get_flags(void *
 {
    uint32_t flags = 0;
 
+   BIT32_SET(flags, GFX_CTX_FLAGS_SHADERS_GLSL);
+
    return flags;
 }
 
