$NetBSD: patch-code_renderergl2_tr__init.c,v 1.1 2021/05/21 15:01:52 nia Exp $

Debian Games Team policy seems to be to default to windowed to avoid
resetting screen geometry, breaking multi-head, etc. r_fullscreen
is "archived" (saved to the user configuration), so this doesn't
affect current players.

Most people will want to configure a higher resolution than 640x480
anyway, at which point it's easy to switch fullscreen on too.

Also set default r_mode to 3 (640x480) in renderergl2, matching
renderergl1.

--- code/renderergl2/tr_init.c.orig	2019-12-07 13:16:15.000000000 +0000
+++ code/renderergl2/tr_init.c
@@ -1203,8 +1203,8 @@ void R_Register( void ) 
 	ri.Cvar_CheckRange( r_ext_multisample, 0, 4, qtrue );
 	r_overBrightBits = ri.Cvar_Get ("r_overBrightBits", "1", CVAR_ARCHIVE | CVAR_LATCH );
 	r_ignorehwgamma = ri.Cvar_Get( "r_ignorehwgamma", "0", CVAR_ARCHIVE | CVAR_LATCH);
-	r_mode = ri.Cvar_Get( "r_mode", "-2", CVAR_ARCHIVE | CVAR_LATCH );
-	r_fullscreen = ri.Cvar_Get( "r_fullscreen", "1", CVAR_ARCHIVE );
+	r_mode = ri.Cvar_Get( "r_mode", "3", CVAR_ARCHIVE | CVAR_LATCH );
+	r_fullscreen = ri.Cvar_Get( "r_fullscreen", "0", CVAR_ARCHIVE );
 	r_noborder = ri.Cvar_Get("r_noborder", "0", CVAR_ARCHIVE | CVAR_LATCH);
 	r_customwidth = ri.Cvar_Get( "r_customwidth", "1600", CVAR_ARCHIVE | CVAR_LATCH );
 	r_customheight = ri.Cvar_Get( "r_customheight", "1024", CVAR_ARCHIVE | CVAR_LATCH );
