$NetBSD: patch-src_sdl_sdl__glimp.c,v 1.1 2024/11/17 09:48:21 nia Exp $

Default fullscreen to off - a bit safer.

--- src/sdl/sdl_glimp.c.orig	2024-08-10 11:04:40.918867331 +0000
+++ src/sdl/sdl_glimp.c
@@ -359,7 +359,7 @@ static void GLimp_InitCvars(void)
 	r_allowResize     = Cvar_Get("r_allowResize", "0", CVAR_ARCHIVE);
 
 	// Window cvars
-	r_fullscreen     = Cvar_Get("r_fullscreen", "1", CVAR_ARCHIVE | CVAR_LATCH);
+	r_fullscreen     = Cvar_Get("r_fullscreen", "0", CVAR_ARCHIVE | CVAR_LATCH);
 	r_noBorder       = Cvar_Get("r_noborder", "0", CVAR_ARCHIVE_ND | CVAR_LATCH);
 	r_centerWindow   = Cvar_Get("r_centerWindow", "0", CVAR_ARCHIVE | CVAR_LATCH);
 	r_customwidth    = Cvar_Get("r_customwidth", "1280", CVAR_ARCHIVE | CVAR_LATCH);
